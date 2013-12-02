#include "libtcap.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "TCMessage.h"
#include "Invoke.h"
#include "InitialDPArg.h"
#include "ConnectArg.h"
#include "FurnishChargingInformationArg.h"




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
