CC=gcc
CFLAGS+=-I../asn1-compiled -I../include -g -Wall -O3 -fPIC
LDFLAGS=-O3 -shared -fPIC -Wl,-soname,$(LIBNAME).so.$(VERSION)

OBJS=tcap.o


.PHONY: all clean


all: $(LIBSO)

$(LIBSOVER): $(OBJS) ../asn1-compiled/libtcap-asn.a
	$(CC) -o $@ $(OBJS) ../asn1-compiled/libtcap-asn.a $(LDFLAGS)

$(LIBSO): $(LIBSOVER)
	ln -fs $(LIBSOVER) $(LIBSO)

clean:
	rm -f $(OBJS)
	rm -f $(LIBSO)
	rm -f $(LIBSOVER)
