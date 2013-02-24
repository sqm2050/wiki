########################################################################
# Code listing from "Advanced Linux Programming," by CodeSourcery LLC  #
# Copyright (C) 2001 by New Riders Publishing                          #
# See COPYRIGHT for license information.                               #
########################################################################

OBJECTS		= readfile.o temp_file.o test.o
LIBRARIES	= libtest.a libtest.so
PROGRAMS	= app arglist client getopt_long print-env tifftest

.PHONY:         all clean

# Default target: build everything.
all:            $(OBJECTS) $(LIBRARIES) $(PROGRAMS)

# Clean up build products.
clean:
	rm -f *.o *.a $(PROGRAMS)

# Additional dependencies.
main:		reciprocal.o

libtest.a:	test.o
	ar cr $@ $?

libtest.so:	test.c
	$(CC) $(CFLAGS) -fPIC -shared $< -o $@

app:		LDLIBS += -L. -ltest
app:		app.c libtest.a

tifftest:	CFLAGS += -static
tifftest:	LDLIBS += -ltiff -ljpeg -lz
