.PHONY: all clean

CPPFLAGS += -I ../include -I../asn1-compiled
CFLAGS := -Wall -g
LDFLAGS += -L../src
LDLIBS += -ltcap

TESTS = basic encode

all: $(TESTS)

clean:
	rm -f $(TESTS)
