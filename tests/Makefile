.PHONY: all clean

CFLAGS+=-Wall -g -I ../include -I../asn1-compiled
LDFLAGS+=-L../src -L../asn1-compiled

all: basic unit_test wrap_tcap_decode

tcap.o: ../src/tcap.c
	gcc -o $@ $(CFLAGS) -c ../src/tcap.c

basic: basic.c tcap.o
	gcc -o $@ $(CFLAGS) basic.c $(LDFLAGS) tcap.o ../asn1-compiled/libtcap-asn.a

unit_test: unit_test.c
	gcc -o $@ $(CFLAGS) unit_test.c $(LDFLAGS) -lcmocka tcap.o ../asn1-compiled/libtcap-asn.a

wrap_tcap_decode: wrap_tcap_decode.c tcap.o
	gcc -o $@ $(CFLAGS) $(LDFLAGS) -lcmocka -Wl,-wrap,tcap_decode -Wl,-undefined,tcap_decode tcap.o ../asn1-compiled/libtcap-asn.a wrap_tcap_decode.c

clean:
	rm -f tcap.o basic unit_test wrap_tcap_decode
