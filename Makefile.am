bin_PROGRAMS = hanoi
man_MANS = hanoi.1

%.1: %
	env PATH=.:$$PATH help2man $< > $@ || $(RM) $@
