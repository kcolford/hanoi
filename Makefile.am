SUBDIRS = lib man

ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = m4/gnulib-cache.m4

#AM_CPPFLAGS = -DNDEBUG

noinst_LIBRARIES = libhanoi.a
libhanoi_a_SOURCES = src/hanoi.c src/hanoi.h

bin_PROGRAMS = hanoi
hanoi_SOURCES = src/main.c src/hanoi.h
hanoi_LDADD = libhanoi.a $(LIBINTL)
