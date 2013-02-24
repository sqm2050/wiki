########################################################################
# Code listing from "Advanced Linux Programming," by CodeSourcery LLC  #
# Copyright (C) 2001 by New Riders Publishing                          #
# See COPYRIGHT for license information.                               #
########################################################################

OBJECTS		= 
LIBRARIES	=
PROGRAMS	= calculator hello malloc-use

.PHONY:         all clean

# Default target: build everything.
all:            $(OBJECTS) $(LIBRARIES) $(PROGRAMS)

# Clean up build products.
clean:
	rm -f *.o *.a $(PROGRAMS)

# Additional dependencies.
calculator.o stack.o number.o: \
		CFLAGS += -pg

calculator:	LDFLAGS += -pg
calculator:	calculator.o stack.o number.o

