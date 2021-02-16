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
	const uint8_t number[] = "1234567890";

	ret = tcap_encode_with_routing(&buf, number, sizeof(number) - 1);
	fprintf(stderr, "ret: %i\n", ret);
	if (ret < 0) {
		fprintf(stderr, "failed to encode tcap\n");
	} else {
		fwrite(buf, ret, 1, stdout);
	}

	free(buf);

	return 0;
}
