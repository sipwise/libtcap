#include <stdio.h>
#include "libtcap.h"
#include "ComponentPortion.h"
#include "Component.h"



//const char tcap[] = "\x64\x81\x86\x49\x03\x0a\x7e\x71\x6b\x2a\x28\x28\x06\x07\x00\x11\x86\x05\x01\x01\x01\xa0\x1d\x61\x1b\xa1\x0d\x06\x0b\x2a\x81\x76\x82\x15\x01\x01\x01\x01\x00\x01\xa2\x03\x02\x01\x00\xa3\x05\xa1\x03\x02\x01\x00\x6c\x53\xa1\x10\x02\x01\x58\x02\x01\x22\xbf\x33\x07\x83\x05\x31\x30\x30\x32\x34\xa1\x3f\x02\x01\x59\x02\x01\x14\x30\x37\xa0\x0e\x04\x0c\x83\x90\x89\x10\x10\x80\x22\x08\x00\x55\x50\x05\x83\x01\x09\x9a\x22\x30\x20\xa0\x1e\x80\x01\x00\x81\x01\x00\x82\x01\x01\x83\x01\x01\x84\x01\x00\x85\x01\x00\x86\x01\x01\x87\x01\x01\x88\x01\x00\x89\x01\x00";
const char tcap[] = "\x62\x51\x48\x03\x0a\x7e\x71\x6b\x22\x28\x20\x06\x07\x00\x11\x86\x05\x01\x01\x01\xa0\x15\x60\x13\x80\x02\x07\x80\xa1\x0d\x06\x0b\x2a\x81\x76\x82\x15\x01\x01\x01\x01\x00\x01\x6c\x26\xa1\x24\x02\x01\x01\x02\x01\x00\x30\x1c\x80\x01\x02\x82\x07\x03\x90\x08\x00\x55\x50\xf5\x83\x07\x83\x13\x17\x45\x64\x86\x08\x85\x01\x0a\x9a\x02\x20\x01";
const int tcap_len = sizeof(tcap) - 1;


int main() {
	int i;
	struct output_buffer out;
	char buf[256];

//	OUTPUT_BUFFER_INIT(&out, buf);
//	i = tcap_extract(tcap, tcap_len, "end.components.1.invoke.opCode.localValue", &out);
//	printf("tcap_extract opcode: returned %i, value %.*s\n", i, (int) out.used, out.buf);
//
//	OUTPUT_BUFFER_INIT(&out, buf);
//	i = inap_extract(tcap, tcap_len, "ConnectArg", &out);
//	printf("inap_extract ConnectArg: returned %i, value %.*s\n", i, (int) out.used, out.buf);
//
//	OUTPUT_BUFFER_INIT(&out, buf);
//	i = inap_extract(tcap, tcap_len, "ConnectArg.cutAndPaste", &out);
//	printf("inap_extract ConnectArg.cutAndPaste: returned %i, value %.*s\n", i, (int) out.used, out.buf);
//
//	OUTPUT_BUFFER_INIT(&out, buf);
//	i = inap_extract(tcap, tcap_len, "ConnectArg.destinationRoutingAddress", &out);
//	printf("inap_extract ConnectArg.destinationRoutingAddress: returned %i, value %.*s\n", i, (int) out.used, out.buf);
//
//	OUTPUT_BUFFER_INIT(&out, buf);
//	i = inap_extract(tcap, tcap_len, "ConnectArg.destinationRoutingAddress.0", &out);
//	printf("inap_extract ConnectArg: returned %i, value %.*s\n", i, (int) out.used, out.buf);

	OUTPUT_BUFFER_INIT(&out, buf);
	i = inap_extract(tcap, tcap_len, "InitialDPArg.calledPartyNumber", &out);
	printf("inap_extract InitialDPArg: returned %i, value %.*s\n", i, (int) out.used, out.buf);

	return 0;
}
