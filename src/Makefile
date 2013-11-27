LIBNAME=libtcap
VERSION=0

CC=gcc
CFLAGS=-I../asn1-compiled -g -Wall -O3 -fPIC
LDFLAGS=-O3 -shared -fPIC -Wl,-soname,$(LIBNAME).so.$(VERSION)

OBJS=tcap.o


.PHONY: all clean


all: $(LIBNAME).so

$(LIBNAME).so: $(OBJS) ../asn1-compiled/libtcap-asn.a
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)
	rm -f $(LIBNAME).so
