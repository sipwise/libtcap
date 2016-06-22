.PHONY: all clean

all: basic encode

basic: basic.c ../src/libtcap.so.0
	gcc -Wall -g -I ../include -I../asn1-compiled basic.c -o basic -L../src -ltcap

encode: encode.c ../src/libtcap.so.0
	gcc -Wall -g -I ../include -I../asn1-compiled encode.c -o encode -L../src -ltcap

clean:
	rm -f basic encode
