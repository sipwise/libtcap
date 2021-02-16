#ifndef _LIBTCAP_H_
#define _LIBTCAP_H_

#include <stddef.h>
#include <stdint.h>

struct output_buffer {
	char *buf;
	size_t buf_size;
	size_t used;
};
#define OUTPUT_BUFFER_INIT(o, i) output_buffer_init(o, i, sizeof(i))
static inline void output_buffer_init(struct output_buffer *o, char *i, size_t s) {
	o->buf = i;
	o->buf_size = s;
	o->used = 0;
}

int tcap_encode_with_routing(char **out, const uint8_t *routing, size_t routing_len);

int tcap_extract(const char *buf, size_t len, const char *spec, struct output_buffer *out);
int inap_extract(const char *buf, size_t len, const char *spec, struct output_buffer *out);
int isup_convert_number(const char *inp, int inlen, char *out);
int isup_convert_number_hex(const char *inp, int inlen, char *out);

#endif
