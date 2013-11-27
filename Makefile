.PHONY: all regenerate-asn1 clean

all:
	$(MAKE) -C asn1-compiled
	$(MAKE) -C src

regenerate-asn1:
	rm -f asn1-compiled/*
	(cd asn1-compiled && asn1c -fskeletons-copy ../asn1/tcap.asn)
	ln -s ../asn1/Makefile.compiled asn1-compiled/Makefile

clean:
	$(MAKE) -C asn1-compiled lib-clean
	$(MAKE) -C src clean
