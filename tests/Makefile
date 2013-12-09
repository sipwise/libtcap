.PHONY: all clean

all: basic unit_test

basic: basic.c ../src/libtcap.so.0
	gcc -Wall -g -I ../include -I../asn1-compiled basic.c -o basic -L../src -ltcap

../src/libtcap.so.0:
	cd .. && make all

unit_test: unit_test.c
	gcc -Wall -g unit_test.c -o unit_test -lcmocka

clean:
	rm -f basic unit_test
