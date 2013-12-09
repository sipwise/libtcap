LIBNAME=libtcap
VERSION=0

LIBDIR=lib
LIB=src/$(LIBNAME).so.$(VERSION)
HDR=include/tcap

DESTDIR?=/usr/local

all:
	$(MAKE) -C asn1-compiled
	$(MAKE) -C src
	$(MAKE) -C tests

regenerate-asn1:
	rm -f asn1-compiled/*
	(cd asn1-compiled && asn1c -fskeletons-copy ../asn1/tcap.asn)
	ln -s ../asn1/Makefile.compiled asn1-compiled/Makefile

clean:
	$(MAKE) -C asn1-compiled lib-clean
	$(MAKE) -C src clean
	$(MAKE) -C tests clean

install: all
	mkdir -p $(DESTDIR)/$(HDR)
	cp include/*.h $(DESTDIR)/$(HDR)
	mkdir -p $(DESTDIR)/$(LIBDIR)
	cp $(LIB) $(DESTDIR)/$(LIBDIR)/$(LIBNAME).so.$(VERSION)
	ln -s $(LIBNAME).so.$(VERSION) $(DESTDIR)/$(LIBDIR)/$(LIBNAME).so

.PHONY: all regenerate-asn1 clean
