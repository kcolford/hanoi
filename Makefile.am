AM_CPPFLAGS = -DNDEBUG
bin_PROGRAMS = hanoi
nodist_man1_MANS = hanoi.1

hanoi.1: hanoi
	$(HELP2MAN) -N ./$< > $@ || $(RM) $@
