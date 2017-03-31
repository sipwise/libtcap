export LIBNAME=libtcap
export VERSION=0
export LIBSO=$(LIBNAME).so
export LIBSOVER=$(LIBNAME).so.$(VERSION)

LIBDIR=lib
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
	rm -rf project.tgz cov-int

install: all
	mkdir -p $(DESTDIR)/$(HDR)
	cp include/*.h $(DESTDIR)/$(HDR)
	cp asn1-compiled/*.h $(DESTDIR)/$(HDR)
	mkdir -p $(DESTDIR)/$(LIBDIR)
	cp src/$(LIBSOVER) $(DESTDIR)/$(LIBDIR)/$(LIBSOVER)
	ln -s $(LIBSOVER) $(DESTDIR)/$(LIBDIR)/$(LIBSO)

coverity:
	cov-build --dir cov-int $(MAKE)
	tar -czf project.tgz cov-int
	curl --form token=$(COVERITY_LIBTCAP_TOKEN) \
		--form email=$(DEBEMAIL) \
		--form file=@project.tgz \
		--form version="$(LIBTCAP_VERSION)" \
		--form description="automatic upload" \
		https://scan.coverity.com/builds?project=$(COVERITY_LIBTCAP_PROJECT)

.PHONY: all regenerate-asn1 clean install coverity
