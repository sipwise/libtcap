.PHONY: all clean

all: basic

basic: basic.c ../src/libtcap.so.0
	gcc -Wall -g -I ../include -I../asn1-compiled basic.c -o basic -L../src -ltcap

clean:
	rm -f basic
