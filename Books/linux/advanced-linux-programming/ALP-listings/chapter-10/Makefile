########################################################################
# Code listing from "Advanced Linux Programming," by CodeSourcery LLC  #
# Copyright (C) 2001 by New Riders Publishing                          #
# See COPYRIGHT for license information.                               #
########################################################################

OBJECTS		= grep-dictionary.o temp-file.o
LIBRARIES	=
PROGRAMS	= pam setuid-test simpleid stat-perm 

.PHONY:         all clean

# Default target: build everything.
all:            $(OBJECTS) $(LIBRARIES) $(PROGRAMS)

# Clean up build products.
clean:
	rm -f *.o *.a $(PROGRAMS)

# Additional dependencies.
pam:		LDLIBS += -lpam -lpam_misc
