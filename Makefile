export LIBNAME=libtcap
export VERSION=1
export LIBSO=$(LIBNAME).so
export LIBSOVER=$(LIBNAME).so.$(VERSION)

LIBDIR=lib
HDR=include/tcap

DESTDIR?=/usr/local

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
	mkdir -p $(DESTDIR)/$(HDR)
	cp include/*.h $(DESTDIR)/$(HDR)
	mkdir -p $(DESTDIR)/$(LIBDIR)
	cp src/$(LIBSOVER) $(DESTDIR)/$(LIBDIR)/$(LIBSOVER)
	ln -s $(LIBSOVER) $(DESTDIR)/$(LIBDIR)/$(LIBSO)

.PHONY: all regenerate-asn1 clean install
