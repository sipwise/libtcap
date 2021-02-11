.PHONY: all clean

CPPFLAGS += -I ../include -I../asn1
CFLAGS := -Wall -g
LDFLAGS += -L../src
LDLIBS += -ltcap

TESTS = basic encode

all: $(TESTS)

test:
	for t in $(TESTS); do \
	  echo "== Testing $$t =="; \
	  if LD_LIBRARY_PATH=../src ./$$t; then \
	    echo; echo "=> $$t: PASS"; \
	  else \
	    echo; echo "=> $$t: FAIL"; \
	  fi; \
	done

clean:
	rm -f $(TESTS)
