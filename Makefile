CFLAGS = -O3
LDFLAGS = -s

all: hanoi

clean:
	$(RM) hanoi

.PHONY: all clean
