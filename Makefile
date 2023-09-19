export LIBNAME = libtcap
export VERSION = 1
export LIBSO = $(LIBNAME).so
export LIBSONAME = $(LIBSO).$(VERSION)

PREFIX ?= /usr/local
HDRDIR ?= $(PREFIX)/include/tcap
LIBDIR ?= $(PREFIX)/lib


all:
	$(MAKE) -C asn1
	$(MAKE) -C src
	$(MAKE) -C tests

regenerate-asn1:
	$(MAKE) -C asn1 dist-clean
	$(MAKE) -C asn1 Makefile.am.sample

test: all
	$(MAKE) -C tests test

clean:
	$(MAKE) -C asn1 lib-clean
	$(MAKE) -C src clean
	$(MAKE) -C tests clean

install: all
	mkdir -p $(DESTDIR)$(HDRDIR)
	cp include/*.h $(DESTDIR)$(HDRDIR)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp src/$(LIBSONAME) $(DESTDIR)$(LIBDIR)
	ln -s $(LIBSONAME) $(DESTDIR)$(LIBDIR)/$(LIBSO)

.PHONY: all regenerate-asn1 clean install
