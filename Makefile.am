bin_PROGRAMS = hanoi
hanoi_CPPFLAGS = -DNDEBUG
man_MANS = hanoi.1

hanoi.1: hanoi
	env PATH=.:$$PATH help2man -N $< > $@ || $(RM) $@

ChangeLog::
	git2cl > $@
