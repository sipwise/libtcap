#ifndef _LIBTCAP_H_
#define _LIBTCAP_H_


#include "TCMessage.h"
#include "Invoke.h"
#include "constr_TYPE.h"


TCMessage_t *tcap_decode(const char *buf, size_t len);
void *inap_decode(Invoke_t *invoke, asn_TYPE_descriptor_t **);
int tcap_extract(const char *buf, size_t len, const char *spec, void *out);


#endif
