CC=gcc
MRUBY_POINTER_ROOT=$(shell pwd)/..
MRUBY_POINTER_SRC=$(MRUBY_POINTER_ROOT)/bintest/shared_ptr.c
MRUBY_POINTER_BIN=$(MRUBY_POINTER_ROOT)/bintest/shared_ptr

MRUBY_ROOT=$(MRUBY_POINTER_ROOT)/mruby
MRUBY_CFLAGS=$(shell $(MRUBY_ROOT)/bin/mruby-config --cflags)
MRUBY_LDFLAGS=$(shell $(MRUBY_ROOT)/bin/mruby-config --ldflags)
MRUBY_LDFLAGS_BEFORE_LIBS=$(shell $(MRUBY_ROOT)/bin/mruby-config --ldflags-before-libs)
MRUBY_LIBS=$(shell $(MRUBY_ROOT)/bin/mruby-config --libs)


all:
	  $(CC) $(MRUBY_POINTER_SRC) $(MRUBY_CFLAGS) $(MRUBY_LDFLAGS) $(MRUBY_LDFLAGS_BEFORE_LIBS) $(MRUBY_LIBS) -o $(MRUBY_POINTER_BIN)

clean:
	-rm shared_ptr
