#include "libtcap.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#include "asn_SET_OF.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_CHOICE.h"

#include "TCMessage.h"
#include "Invoke.h"
#include "InitialDPArg.h"
#include "ConnectArg.h"
#include "FurnishChargingInformationArg.h"
#include "INTEGER.h"




#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

#define INVOKE_OPCODE_INITIALDP				0
#define INVOKE_OPCODE_CONNECT				20
#define INVOKE_OPCODE_FURNISHCHARGINGINFORMATION	34


static asn_TYPE_descriptor_t *opcode_type_map[] = {
	[INVOKE_OPCODE_INITIALDP]			= &asn_DEF_InitialDPArg,
	[INVOKE_OPCODE_CONNECT]				= &asn_DEF_ConnectArg,
	[INVOKE_OPCODE_FURNISHCHARGINGINFORMATION]	= &asn_DEF_FurnishChargingInformationArg,
};



TCMessage_t *tcap_decode(const char *buf, size_t len) {
	TCMessage_t *ret = NULL;
	asn_dec_rval_t rv;

	rv = ber_decode(0, &asn_DEF_TCMessage, (void **) &ret, buf, len);

	if (rv.code == RC_OK)
		return ret;

	asn_DEF_TCMessage.free_struct(&asn_DEF_TCMessage, ret, 0);
	return NULL;
}

void *inap_decode(Invoke_t *invoke, asn_TYPE_descriptor_t **type) {
	long opcode;
	int rv;
	void *arg = 0;

	if (!invoke || !invoke->parameter || !type)
		goto nothing;

	if (invoke->opCode.present != OPERATION_PR_localValue)
		goto nothing;

	if (asn_INTEGER2long(&invoke->opCode.choice.localValue, &opcode))
		goto nothing;

	if (opcode >= ARRAY_SIZE(opcode_type_map))
		goto nothing;

	*type = opcode_type_map[opcode];

	rv = ANY_to_type(invoke->parameter, *type, &arg);

	if (!rv)
		return arg;

	if (arg)
		(*type)->free_struct(*type, arg, 0);

nothing:
	*type = NULL;
	return NULL;
}

int tcap_extract(const char *buf, size_t len, const char *spec, void *out) {
	void *element;
	asn_TYPE_descriptor_t *type;
	const char *c;
	const char *token;
	int token_len, i, num;
	asn_TYPE_member_t *member;
	asn_anonymous_set_ *list;
	asn_CHOICE_specifics_t *choice_spec;

	element = tcap_decode(buf, len);
	if (!element)
		goto error;
	type = &asn_DEF_TCMessage;

	token = spec;

	while (1) {
		c = strchr(token, '.');
		if (!c)
			token_len = strlen(token);
		else
			token_len = c - token;

		if (token_len <= 0)
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
		if (member->flags & ATF_POINTER)
			element = *((void **) element);

found_element:
		if (!c)
			break;

		token = c + 1;
	}

	/* found our target value, check for primitive types */
	if (type->elements_count)
		goto out;

	if (type == &asn_DEF_INTEGER) {
		if (asn_INTEGER2long(element, out))
			goto error;
	}

out:
	return 0;

error:
	return -1;
}
