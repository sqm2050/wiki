########################################################################
# Code listing from "Advanced Linux Programming," by CodeSourcery LLC  #
# Copyright (C) 2001 by New Riders Publishing                          #
# See COPYRIGHT for license information.                               #
########################################################################

OBJECTS		= cleanup.o condvar.o critical-section.o cxx-exit.o \
		  job-queue1.o job-queue2.o job-queue3.o spin-condvar.o
LIBRARIES	=
PROGRAMS	= detached primes thread-create thread-create2 \
		  thread-pid tsd

# Link programs with the pthread library.
LDLIBS		+= -lpthread

.PHONY:         all clean

# Default target: build everything.
all:            $(OBJECTS) $(LIBRARIES) $(PROGRAMS)

# Clean up build products.
clean:
	rm -f *.o *.a $(PROGRAMS)
