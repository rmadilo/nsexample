#
# $Header: /cvsroot/aolserver/nsexample/Makefile,v 1.1 2000/08/20 19:12:26 kriston Exp $
#
# nsexample --
#
#      Example AOLserver module Makefile.
#

#
# AOLserver's location
#
#  Since your module probably doesn't live inside the "aolserver"
#  directory, you can tell make where to find aolserver.
#
#NSHOME   =  /home/user/cvs/aolserver
NSHOME   =  ../aolserver

#
# Module name
#
MOD      =  nsexample.so

#
# Objects to build
#
OBJS     =  nsexample.o

#
# Header files in THIS directory (included with your module)
#
HDRS     =  

#
# Extra libraries required by your module (-L and -l go here)
#
MODLIBS  =  

#
# Compiler flags required by your module (-I for external headers goes here)
#
CFLAGS   =  


include  $(NSHOME)/include/Makefile.module

