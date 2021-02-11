CC=gcc

CPPFLAGS += -I../asn1-compiled -I../include
CFLAGS := -g -Wall -O3
CFLAGS += -fPIC
LDFLAGS := -O3
LDFLAGS += -shared -fPIC -Wl,-soname,$(LIBNAME).so.$(VERSION)

OBJS=tcap.o


.PHONY: all clean


all: $(LIBSO)

$(LIBSOVER): $(OBJS) ../asn1-compiled/libtcap-asn.a
	$(CC) $(CFLAGS) -o $@ $(OBJS) ../asn1-compiled/libtcap-asn.a $(LDFLAGS)

$(LIBSO): $(LIBSOVER)
	ln -fs $(LIBSOVER) $(LIBSO)

clean:
	rm -f $(OBJS)
	rm -f $(LIBSO)
	rm -f $(LIBSOVER)
