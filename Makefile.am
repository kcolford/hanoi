bin_PROGRAMS = hanoi
man1_MANS = hanoi.1

%.1: %
	help2man ./$< > $@ || $(RM) $@
