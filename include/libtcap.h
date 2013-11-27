#ifndef _LIBTCAP_H_
#define _LIBTCAP_H_


#include "TCMessage.h"


TCMessage_t *tcap_decode(const char *buf, size_t len);


#endif
