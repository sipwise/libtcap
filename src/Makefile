LIBNAME=libtcap
VERSION=0

CC=gcc
CFLAGS=-I../asn1-compiled -I../include -g -Wall -O3 -fPIC
LDFLAGS=-O3 -shared -fPIC -Wl,-soname,$(LIBNAME).so.$(VERSION)

OBJS=tcap.o


.PHONY: all clean


all: $(LIBNAME).so

$(LIBNAME).so.$(VERSION): $(OBJS) ../asn1-compiled/libtcap-asn.a
	$(CC) -o $@ $(OBJS) ../asn1-compiled/libtcap-asn.a $(LDFLAGS)

$(LIBNAME).so: $(LIBNAME).so.$(VERSION)
	ln -s $(LIBNAME).so.$(VERSION) $(LIBNAME).so

clean:
	rm -f $(OBJS)
	rm -f $(LIBNAME).so
	rm -f $(LIBNAME).so.$(VERSION)
