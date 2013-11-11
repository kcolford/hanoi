#AM_CPPFLAGS = -DNDEBUG

noinst_LIBRARIES = libhanoi.a
libhanoi_a_SOURCES = hanoi.c hanoi.h

bin_PROGRAMS = hanoi
hanoi_SOURCES = main.c hanoi.h
hanoi_LDADD = libhanoi.a

man_MANS = hanoi.1
CLEANFILES = $(man_MANS)

hanoi.1: main.c
	$(HELP2MAN) -N ./hanoi > $@ || $(RM) $@
