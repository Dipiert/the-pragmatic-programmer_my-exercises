CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: src/tpp11.c src/tpp11.h
	@echo Compiling $@
	@cc $(CFLAGS) src/tpp11.c src/tpp11.h -o tests.out -lm
