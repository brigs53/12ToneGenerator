EXEC	= main
OBJECTS1	= main.o
CFLAGS	= -Wall -Wextra -Werror -Wpedantic -std=c99 -g
CC	= clang -g

.PHONY: all clean

all: $(EXEC)

main	: $(OBJECTS1)
	$(CC) -o main $(OBJECTS1) -lm

main.o	: main.c
		$(CC) -c main.c

clean	:
	        rm -f $(EXEC) $(OBJECTS1)

infer	:
	        make clean; infer-capture -- make; infer-analyze -- make

format	:
	        clang-format -i -style=file *.c *.h
formatc	:
	        clang-format -i -style=file *.c
formath	:
	        clang-format -i -style=file *.h
valgrind:
	        valgrind main;
