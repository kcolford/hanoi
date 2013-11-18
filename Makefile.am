ACLOCAL_AMFLAGS = -I m4
SUBDIRS = lib
EXTRA_DIST = m4/gnulib-cache.m4

#AM_CPPFLAGS = -DNDEBUG

noinst_LIBRARIES = libhanoi.a
libhanoi_a_SOURCES = src/hanoi.c src/hanoi.h

bin_PROGRAMS = hanoi
hanoi_SOURCES = src/main.c src/hanoi.h
hanoi_LDADD = libhanoi.a $(LIBINTL)

dist_man_MANS = hanoi.1

hanoi.1: src/main.c configure.ac
	$(HELP2MAN) --name="solve the puzzle" -N ./hanoi -o $@
