SUBDIRS = lib

ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = m4/gnulib-cache.m4

DISTCLEANFILES = $(dist_man1_MANS)

#AM_CPPFLAGS = -DNDEBUG

noinst_LIBRARIES = libhanoi.a
libhanoi_a_SOURCES = src/hanoi.c src/hanoi.h

bin_PROGRAMS = hanoi
hanoi_SOURCES = src/main.c src/hanoi.h
hanoi_LDADD = libhanoi.a $(LIBINTL)

dist_man1_MANS = hanoi.1

hanoi.1: hanoi
	$(HELP2MAN) ./$< -o $@
