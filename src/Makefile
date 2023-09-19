CC=gcc

CPPFLAGS += -I../asn1 -I../include
CFLAGS := -g -Wall -O3
CFLAGS += -fPIC -D_DEFAULT_SOURCE
LDFLAGS := -O3
LDFLAGS += -shared -fPIC -Wl,-soname,$(LIBSONAME)
LDFLAGS += -Wl,--version-script=libtcap.map

OBJS=tcap.o


.PHONY: all clean


all: $(LIBSO)

$(LIBSONAME): $(OBJS) ../asn1/libtcap-asn.a
	$(CC) $(CFLAGS) -o $@ $(OBJS) ../asn1/libtcap-asn.a $(LDFLAGS)

$(LIBSO): $(LIBSONAME)
	ln -fs $(LIBSONAME) $(LIBSO)

clean:
	rm -f $(OBJS)
	rm -f $(LIBSO)
	rm -f $(LIBSONAME)
