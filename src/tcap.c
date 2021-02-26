#include "libtcap.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#include "asn_SET_OF.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_CHOICE.h"

#include "CalledPartyNumber.h"
#include "Component.h"
#include "ComponentPortion.h"
#include "ConnectArg.h"
#include "FurnishChargingInformationArg.h"
#include "INTEGER.h"
#include "InitialDPArg.h"
#include "Invoke.h"
#include "TCMessage.h"




#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

#define INVOKE_OPCODE_INITIALDP				0
#define INVOKE_OPCODE_CONNECT				20
#define INVOKE_OPCODE_FURNISHCHARGINGINFORMATION	34


static asn_TYPE_descriptor_t *opcode_type_map[] = {
	[INVOKE_OPCODE_INITIALDP]			= &asn_DEF_InitialDPArg,
	[INVOKE_OPCODE_CONNECT]				= &asn_DEF_ConnectArg,
	[INVOKE_OPCODE_FURNISHCHARGINGINFORMATION]	= &asn_DEF_FurnishChargingInformationArg,
};



static int buf_append(const void *buffer, size_t size, void *app_key) {
	FILE *fp = app_key;
	size_t ret;

	if (!buffer || !size)
		return 0;
	//fprintf(stderr, "writing %p %lu\n", buffer, size);
	ret = fwrite(buffer, size, 1, fp);
	return (ret == 1) ? 0 : -1;
}

static int tcap_encode(char **out, TCMessage_t *msg) {
	FILE *fp;
	char *str;
	size_t len;
	asn_enc_rval_t ec;

	fp = open_memstream(&str, &len);
	if (!fp)
		return -1;

	ec = der_encode(&asn_DEF_TCMessage, msg, buf_append, fp);

	fclose(fp);

	if (ec.encoded == -1) {
		free(str);
		return -1;
	}

	*out = str;
	return len;
}

int tcap_encode_with_routing(char **out, const uint8_t *routing, size_t routing_len) {
	int ret;
	TCMessage_t msg;
	ComponentPortion_t cp;
	Component_t *cmp_arr;
	Component_t cmp;
	ConnectArg_t ca;
	CalledPartyNumber_t *cpn_arr;
	CalledPartyNumber_t cpn;

	// init first
	memset(&msg, 0, sizeof(msg));
	memset(&cp, 0, sizeof(cp));
	memset(&cmp, 0, sizeof(cmp));
	memset(&ca, 0, sizeof(ca));
	memset(&cpn, 0, sizeof(cpn));

	cpn.buf = (uint8_t *)routing;
	cpn.size = routing_len;

	// fill structs
	msg.present = TCMessage_PR_begin;
	msg.choice.begin.components = &cp;

	cmp_arr = &cmp;
	cp.list.count = 1;
	cp.list.array = &cmp_arr;

	cmp.present = Component_PR_invoke;
	cmp.choice.invoke.opCode.present = OPERATION_PR_localValue;
	cmp.choice.invoke.opCode.choice.localValue = 20; // connect

	cpn_arr = &cpn;
	ca.destinationRoutingAddress.list.count = 1;
	ca.destinationRoutingAddress.list.array = &cpn_arr;

	cmp.choice.invoke.parameter = ANY_new_fromType(&asn_DEF_ConnectArg, &ca);

	ret = tcap_encode(out, &msg);

	asn_DEF_ANY.free_struct(&asn_DEF_ANY, cmp.choice.invoke.parameter, 0);

	return ret;
}

static TCMessage_t *tcap_decode(const char *buf, size_t len) {
	TCMessage_t *ret = NULL;
	asn_dec_rval_t rv;

	rv = ber_decode(0, &asn_DEF_TCMessage, (void **) &ret, buf, len);

	if (rv.code == RC_OK)
		return ret;

	asn_DEF_TCMessage.free_struct(&asn_DEF_TCMessage, ret, 0);
	return NULL;
}

static void *inap_decode(Invoke_t *invoke, asn_TYPE_descriptor_t **type) {
	long opcode;
	int rv;
	void *arg = 0;

	if (!invoke || !invoke->parameter || !type)
		goto nothing;

	if (invoke->opCode.present != OPERATION_PR_localValue)
		goto nothing;

	opcode = invoke->opCode.choice.localValue;

	if (opcode >= ARRAY_SIZE(opcode_type_map))
		goto nothing;

	*type = opcode_type_map[opcode];
	if (!*type)
		goto nothing;

	rv = ANY_to_type(invoke->parameter, *type, &arg);

	if (!rv)
		return arg;

	if (arg)
		(*type)->free_struct(*type, arg, 0);

nothing:
	if(type)
		*type = NULL;
	return NULL;
}

static inline int next_token_1(const char **token, int *token_len, const char **c) {
	*c = strchr(*token, '.');
	if (!*c)
		*token_len = strlen(*token);
	else
		*token_len = *c - *token;

	if (*token_len <= 0)
		return -1;

	return 0;
}

static inline int next_token_2(const char **token, const char **c) {
	if (!*c)
		return -1;

	*token = *c + 1;
	return 0;
}

static int cb(const void *buf, size_t s, void *app_key) {
	struct output_buffer *out = app_key;

	if (out->buf_size - out->used < s)
		return -1;
	memcpy(out->buf + out->used, buf, s);
	out->used += s;
	return 0;
}

static int asn1_extract(const char *spec, struct output_buffer *out, asn_TYPE_descriptor_t *type,
		void *element)
{
	const char *token, *c;
	int token_len, i, num;
	asn_TYPE_member_t *member;
	asn_anonymous_set_ *list;
	asn_CHOICE_specifics_t *choice_spec;

	if (!element)
		goto error;

	token = spec;

	while (1) {
		if (next_token_1(&token, &token_len, &c))
			goto error;

		if (type->elements_count <= 0)
			goto error; /* ? */

		/* check if we have a number */
		for (i = 0; i < token_len; i++) {
			if (token[i] < '0' || token[i] > '9')
				goto word;
		}

		/* we should have an array here */
		num = atoi(token);
		if (num < 0)
			goto error;

		/* single element with empty name == array ??? */
		if (type->elements_count > 1
				|| type->elements[0].name[0] != '\0')
			goto error;

		list = _A_SET_FROM_VOID(element);
		if (num >= list->count)
			goto error;

		element = list->array[num];
		type = type->elements[0].type;
		goto found_element;

word:
		/* has to be a CHOICE, SET or SEQUENCE */
		for (i = 0; i < type->elements_count; i++) {
			member = &type->elements[i];
			if (!strncmp(token, member->name, token_len))
				goto found_member;
		}

		goto error;

found_member:
		/* if this is a CHOICE, we need to confirm the member. we use the
		 * print function pointer to determine. i is the struct index */
		if (type->print_struct == CHOICE_print) {
			choice_spec = type->specifics;
			if (choice_spec->pres_size != sizeof(int))
				goto error;
			num = *((int *) element + choice_spec->pres_offset);
			if (num != i + 1)
				goto error;
		}

		type = member->type;
		element = element + member->memb_offset;
		if (element && (member->flags & ATF_POINTER))
			element = *((void **) element);
		if (!element)
			break;

found_element:
		if (next_token_2(&token, &c))
			break;
	}

	if (type->print_struct && out)
		type->print_struct(type, element, 0, cb, out);

	return 0;

error:
	return -1;
}



int tcap_extract(const char *buf, size_t len, const char *spec, struct output_buffer *out) {
	TCMessage_t *tcm;
	int ret;

	tcm = tcap_decode(buf, len);
	if (!tcm)
		return -1;

	ret = asn1_extract(spec, out, &asn_DEF_TCMessage, tcm);

	asn_DEF_TCMessage.free_struct(&asn_DEF_TCMessage, tcm, 0);
	return ret;
}



int inap_extract(const char *buf, size_t len, const char *spec, struct output_buffer *out) {
	TCMessage_t *tcm;
	ComponentPortion_t *cp;
	Component_t *cmp;
	Invoke_t *inv;
	const char *token, *c;
	int token_len, i;
	void *parameter;
	asn_TYPE_descriptor_t *type;

	tcm = tcap_decode(buf, len);
	if (!tcm)
		goto error;

	switch (tcm->present) {
		case TCMessage_PR_unidirectional:
			cp = &tcm->choice.unidirectional.components;
			break;

		case TCMessage_PR_begin:
			cp = tcm->choice.begin.components;
			break;

		case TCMessage_PR_end:
			cp = tcm->choice.end.components;
			break;

		case TCMessage_PR_continue:
			cp = tcm->choice.Continue.components;
			break;

		default:
			goto error;
	}

	if (!cp)
		goto error;

	token = spec;

	/* first token is the type we're looking for */

	if (next_token_1(&token, &token_len, &c))
		goto error;

	for (i = 0; i < cp->list.count; i++) {
		cmp = cp->list.array[i];
		if (cmp->present != Component_PR_invoke)
			continue;
		inv = &cmp->choice.invoke;

		parameter = inap_decode(inv, &type);
		if (!parameter)
			continue;

		if (!strncmp(type->name, token, token_len))
			goto found_parameter;
	}

	goto error;

found_parameter:
	if (next_token_2(&token, &c))
		i = 0;
	else
		i = asn1_extract(token, out, type, parameter);

	asn_DEF_TCMessage.free_struct(&asn_DEF_TCMessage, tcm, 0);
	type->free_struct(type, parameter, 0);

	return i;

error:
	if (tcm)
		asn_DEF_TCMessage.free_struct(&asn_DEF_TCMessage, tcm, 0);
	return -1;
}


static inline char phone_digit(unsigned char d) {
	if (d <= 9)
		return '0' + d;
	switch (d) {
		case 11:
			return '*';
		case 12:
			return '#';
		case 15:
			return 'F';
		default:
			return '?';
	}
}

static inline char phone_digit_hex(unsigned char d) {
	if (d <= 9)
		return '0' + d;
	else if (d <= 15)
		return 'A' + d - 10;
	return '?';
}


static inline int isup_convert_number_common(const char *inp, int inlen, char *out,
		char (*func)(unsigned char))
{
	const char *pi;
	unsigned char raw[32] = "", *pr;
	int rawlen, odd;

	if (inlen < 0)
		inlen = strlen(inp);

	if (inlen < 5) /* min: 2 octets */
		goto error;
	if (inlen > 92) /* 31 * 2 + 30 */
		goto error;

	pr = raw;
	pi = inp;
	while (1) {
		if (!*pi)
			break;

		if (*pi >= '0' && *pi <= '9')
			*pr = (*pi - '0') << 4;
		else if (*pi >= 'A' && *pi <= 'F')
			*pr = (*pi - 'A' + 10) << 4;
		else if (*pi >= 'a' && *pi <= 'f')
			*pr = (*pi - 'a' + 10) << 4;
		else
			goto error;

		pi++;

		if (*pi >= '0' && *pi <= '9')
			*pr |= (*pi - '0');
		else if (*pi >= 'A' && *pi <= 'F')
			*pr |= (*pi - 'A' + 10);
		else if (*pi >= 'a' && *pi <= 'f')
			*pr |= (*pi - 'a' + 10);
		else
			goto error;

		pr++;

		pi++;
		if (!*pi)
			break;
		if (*pi != ' ')
			goto error;
		pi++;
	}

	rawlen = pr - raw;

	odd = raw[0] & 0x80;
	if (odd && rawlen == 2)
		goto error;

	pr = raw + 2;
	rawlen -= 2;
	while (rawlen) {
		*(out++) = func(*pr & 0xf);
		*(out++) = func(*pr >> 4);
		rawlen--;
		pr++;
	}

	if (odd)
		out--;

	*out = 0;

	return 0;

error:
	return -1;
}

int isup_convert_number(const char *inp, int inlen, char *out) {
	return isup_convert_number_common(inp, inlen, out, phone_digit);
}
int isup_convert_number_hex(const char *inp, int inlen, char *out) {
	return isup_convert_number_common(inp, inlen, out, phone_digit_hex);
}
