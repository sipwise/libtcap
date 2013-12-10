.PHONY: all clean

CFLAGS+=-Wall -g -I ../include -I../asn1-compiled
LDFLAGS+=-L../src -L../asn1-compiled

all: basic unit_test wrap_tcap_decode

basic: basic.c ../src/libtcap.so.0
	gcc -o $@ $(CFLAGS) basic.c $(LDFLAGS) ../src/tcap.o ../asn1-compiled/libtcap-asn.a

../src/tcap.o: ../src/tcap.c
	gcc -o $@ $(CFLAGS) -c ../src/tcap.c

unit_test: unit_test.c
	gcc -o $@ $(CFLAGS) unit_test.c $(LDFLAGS) -lcmocka ../src/tcap.o ../asn1-compiled/libtcap-asn.a

wrap_tcap_decode: wrap_tcap_decode.c
	gcc -o $@ $(CFLAGS) $(LDFLAGS) -lcmocka -Wl,-wrap,cap_decode ../src/tcap.o ../asn1-compiled/libtcap-asn.a wrap_tcap_decode.c

clean:
	rm -f basic unit_test wrap_tcap_decode
