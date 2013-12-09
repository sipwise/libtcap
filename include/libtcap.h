#ifndef _LIBTCAP_H_
#define _LIBTCAP_H_


#include "TCMessage.h"
#include "Invoke.h"
#include "constr_TYPE.h"


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



TCMessage_t *tcap_decode(const char *buf, size_t len);
void *inap_decode(Invoke_t *invoke, asn_TYPE_descriptor_t **);
int tcap_extract(const char *buf, size_t len, const char *spec, struct output_buffer *out);
int inap_extract(const char *buf, size_t len, const char *spec, struct output_buffer *out);


#endif
