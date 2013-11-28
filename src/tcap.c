#include "libtcap.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "TCMessage.h"
#include "Invoke.h"
#include "InitialDPArg.h"
#include "ConnectArg.h"
#include "FurnishChargingInformationArg.h"




#define INVOKE_OPCODE_INITIALDP				0
#define INVOKE_OPCODE_CONNECT				20
#define INVOKE_OPCODE_FURNISHCHARGINGINFORMATION	34



TCMessage_t *tcap_decode(const char *buf, size_t len) {
	TCMessage_t *ret = NULL;
	asn_dec_rval_t rv;

	rv = ber_decode(0, &asn_DEF_TCMessage, (void **) &ret, buf, len);

	if (rv.code == RC_OK)
		return ret;

	asn_DEF_TCMessage.free_struct(&asn_DEF_TCMessage, ret, 0);
	return NULL;
}

void *inap_decode(Invoke_t *invoke) {
	long opcode;
	int rv;
	void *arg = 0;

	if (!invoke || !invoke->parameter)
		goto nothing;

	if (invoke->opCode.present != OPERATION_PR_localValue)
		goto nothing;

	if (asn_INTEGER2long(&invoke->opCode.choice.localValue, &opcode))
		goto nothing;

	switch (opcode) {
		case INVOKE_OPCODE_INITIALDP:
			rv = ANY_to_type(invoke->parameter, &asn_DEF_InitialDPArg, &arg);
			break;

		case INVOKE_OPCODE_CONNECT:
			rv = ANY_to_type(invoke->parameter, &asn_DEF_ConnectArg, &arg);
			break;

		case INVOKE_OPCODE_FURNISHCHARGINGINFORMATION:
			rv = ANY_to_type(invoke->parameter, &asn_DEF_FurnishChargingInformationArg, &arg);
			break;

		default:
			goto nothing;
	}

	if (!rv)
		return arg;

	/* free struct */

nothing:
	return NULL;
}
