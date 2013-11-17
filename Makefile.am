ACLOCAL_AMFLAGS = -I m4
SUBDIRS = lib
EXTRA_DIST = m4/gnulib-cache.m4

AM_CPPFLAGS = -DNDEBUG
AM_CFLAGS = -ggdb3 -pg

noinst_LIBRARIES = libhanoi.a
libhanoi_a_SOURCES = hanoi.c hanoi.h

bin_PROGRAMS = hanoi
hanoi_SOURCES = main.c hanoi.h
hanoi_LDADD = libhanoi.a $(LIBINTL)

man_MANS = hanoi.1
MAINTAINERCLEAN = $(man_MANS)

hanoi.1: hanoi.c
	$(HELP2MAN) --name="solve the puzzle" -N ./hanoi -o $@
