#
# $Id: Makefile,v 1.2 2003/11/01 12:12:48 vasiljevic Exp $
#
# nsexample --
#
# Example AOLserver module Makefile.
#

#
# AOLserver's location
#
# Since your module probably doesn't live inside the "aolserver"
# directory, you can tell make where to find aolserver.
#
NSHOME	=  /usr/local/aolserver

#
# Module name
#
MOD		= nsexample.so

#
# Objects to build
#
OBJS	= nsexample.o

#
# Header files in THIS directory (included with your module)
#
HDRS	=

#
# Extra libraries required by your module (-L and -l go here)
#
MODLIBS	=

#
# Compiler flags required by your module (-I for external headers goes here)
#
CFLAGS	=

include  $(NSHOME)/include/Makefile.module

# EOF $RCSfile: Makefile,v $