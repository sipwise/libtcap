#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libtcap.h"
#include "TCMessage.h"
#include "ComponentPortion.h"
#include "Component.h"
#include "ConnectArg.h"
#include "CalledPartyNumber.h"

int main() {
	char *buf;
	int ret;
	TCMessage_t msg;
	ComponentPortion_t cp;
	Component_t *cmp_arr;
	Component_t cmp;
	ConnectArg_t ca;
	CalledPartyNumber_t *cpn_arr;
	CalledPartyNumber_t cpn;

	memset(&msg, 0, sizeof(msg));
	memset(&cp, 0, sizeof(cp));
	memset(&cmp, 0, sizeof(cmp));
	memset(&ca, 0, sizeof(ca));
	memset(&cpn, 0, sizeof(cpn));

	msg.present = TCMessage_PR_begin;
	msg.choice.begin.components = &cp;

	cp.list.count = 1;
	cmp_arr = &cmp;
	cp.list.array = &cmp_arr;

	cmp.present = Component_PR_invoke;
	cmp.choice.invoke.opCode.present = OPERATION_PR_localValue;
	asn_long2INTEGER(&cmp.choice.invoke.opCode.choice.localValue, 20); // connect

	ca.destinationRoutingAddress.list.count = 1;
	cpn_arr = &cpn;
	ca.destinationRoutingAddress.list.array = &cpn_arr;

	cpn.buf = "1234567890";
	cpn.size = 10;

	cmp.choice.invoke.parameter = ANY_new_fromType(&asn_DEF_ConnectArg, &ca);

	ret = tcap_encode(&buf, &msg);
	fprintf(stderr, "ret: %i\n", ret);
    if(ret < 0) {
	    fprintf(stderr, "failed to encode tcap\n");
    } else {
	    fwrite(buf, ret, 1, stdout);
    }

	free(buf);
	asn_DEF_ANY.free_struct(&asn_DEF_ANY, cmp.choice.invoke.parameter, 0);
	asn_DEF_INTEGER.free_struct(&asn_DEF_INTEGER, &cmp.choice.invoke.opCode.choice.localValue, 0);

	return 0;
}
