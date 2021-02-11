.PHONY: all lib clean lib-clean

LIBNAME=libtcap-asn.a

CFLAGS = -g -Wall -O3
CFLAGS += -fPIC -D_DEFAULT_SOURCE

lib: $(LIBNAME)

-include Makefile.am.sample

Makefile.am.sample: tcap.asn
	asn1c $<
	patch -p1 <tcap-generated.patch

LIB_OBJS=${ASN_MODULE_SOURCES:.c=.o}

$(LIBNAME): $(LIB_OBJS) Makefile.am.sample
	ar cr $(LIBNAME) $(LIB_OBJS)

lib-clean: clean
	$(RM) $(LIBNAME)

dist-clean: lib-clean
	$(RM) Makefile.am.sample
	$(RM) *.c *.h
