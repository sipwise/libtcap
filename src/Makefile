CC=gcc

CPPFLAGS += -I../asn1 -I../include
CFLAGS := -g -Wall -O3
CFLAGS += -fPIC -D_DEFAULT_SOURCE
LDFLAGS := -O3
LDFLAGS += -shared -fPIC -Wl,-soname,$(LIBNAME).so.$(VERSION)
LDFLAGS += -Wl,--version-script=libtcap.map

OBJS=tcap.o


.PHONY: all clean


all: $(LIBSO)

$(LIBSOVER): $(OBJS) ../asn1/libtcap-asn.a
	$(CC) $(CFLAGS) -o $@ $(OBJS) ../asn1/libtcap-asn.a $(LDFLAGS)

$(LIBSO): $(LIBSOVER)
	ln -fs $(LIBSOVER) $(LIBSO)

clean:
	rm -f $(OBJS)
	rm -f $(LIBSO)
	rm -f $(LIBSOVER)
