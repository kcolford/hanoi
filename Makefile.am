AM_CPPFLAGS = -DNDEBUG

noinst_LIBRARIES = libhanoi.a
libhanoi_a_SOURCES = hanoi.c hanoi.h

bin_PROGRAMS = hanoi
hanoi_SOURCES = main.c hanoi.h
hanoi_LDADD = libhanoi.a

dist_MANS = hanoi.1

hanoi.1: hanoi
	$(HELP2MAN) -N ./$< > $@ || $(RM) $@
