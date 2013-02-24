########################################################################
# Code listing from "Advanced Linux Programming," by CodeSourcery LLC  #
# Copyright (C) 2001 by New Riders Publishing                          #
# See COPYRIGHT for license information.                               #
########################################################################

OBJECTS		= read-file.o write-all.o
LIBRARIES	=
PROGRAMS	= create-file hexdump listdir lseek-huge timestamp write-args

.PHONY:         all clean

# Default target: build everything.
all:            $(OBJECTS) $(LIBRARIES) $(PROGRAMS)

# Clean up build products.
clean:
	rm -f *.o *.a $(PROGRAMS)
