#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "libtcap.h"
#include "TCMessage.h"

TCMessage_t *__wrap_tcap_decode(const char *buf, size_t len) {
	TCMessage_t *ret = NULL;

	printf("Hi\n");
	check_expected(buf);
	check_expected(len);

	// allways fail
	return ret;
}

const char tcap[] = "\x64\x81\x86\x49\x03\x0a\x7e\x71\x6b\x2a\x28\x28\x06\x07\x00\x11\x86\x05\x01\x01\x01\xa0\x1d\x61\x1b\xa1\x0d\x06\x0b\x2a\x81\x76\x82\x15\x01\x01\x01\x01\x00\x01\xa2\x03\x02\x01\x00\xa3\x05\xa1\x03\x02\x01\x00\x6c\x53\xa1\x10\x02\x01\x58\x02\x01\x22\xbf\x33\x07\x83\x05\x31\x30\x30\x32\x34\xa1\x3f\x02\x01\x59\x02\x01\x14\x30\x37\xa0\x0e\x04\x0c\x83\x90\x89\x10\x10\x80\x22\x08\x00\x55\x50\x05\x83\x01\x09\x9a\x22\x30\x20\xa0\x1e\x80\x01\x00\x81\x01\x00\x82\x01\x01\x83\x01\x01\x84\x01\x00\x85\x01\x00\x86\x01\x01\x87\x01\x01\x88\x01\x00\x89\x01\x00";
const int tcap_len = sizeof(tcap) - 1;
struct output_buffer out;
char buf[256];

static void test_localValue(void **state) {
    int i;
	OUTPUT_BUFFER_INIT(&out, buf);

	//expect_memory(__wrap_tcap_decode, buf, tcap, tcap_len);
	//expect_value(__wrap_tcap_decode, len, tcap_len);

	i = tcap_extract(tcap, tcap_len, "end.components.1.invoke.opCode.localValue", &out);
    assert_int_equal(i, 0);
    assert_int_equal(out.used, 2);
    out.buf[2] = '\0';
    assert_string_equal(out.buf, "20");
}

int main(void) {
    const UnitTest tests[] = {
        unit_test(test_localValue),
    };
    return run_tests(tests);
}