dist_man1_MANS = hanoi.1

hanoi.1: ../src/main.c ../configure.ac
	$(HELP2MAN) --name="solve the puzzle" -N ../hanoi -o $@
