# stub


.PHONY: all regenerate-asn1

all:
	exit 1

regenerate-asn1:
	rm -f asn1-compiled/*
	(cd asn1-compiled && asn1c -fskeletons-copy ../asn1/tcap.asn)
