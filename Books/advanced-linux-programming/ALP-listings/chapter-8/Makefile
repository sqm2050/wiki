########################################################################
# Code listing from "Advanced Linux Programming," by CodeSourcery LLC  #
# Copyright (C) 2001 by New Riders Publishing                          #
# See COPYRIGHT for license information.                               #
########################################################################

OBJECTS		= better_sleep.o print-cpu-times.o print-time.o \
		  write_journal_entry.o
LIBRARIES	= 
PROGRAMS	= check-access copy itimer limit-cpu lock-file mprotect \
		  print-symlink print-uname sysinfo 

.PHONY:         all clean

# Default target: build everything.
all:            $(OBJECTS) $(LIBRARIES) $(PROGRAMS)

# Clean up build products.
clean:
	rm -f *.o *.a $(PROGRAMS)
