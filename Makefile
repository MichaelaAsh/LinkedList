L4: L4.o
	gcc -ansi -Wall -o L4 L4.o

L4.o: L4.c
	gcc -ansi -Wall -c L4.c

all: L4

clean: L4.c
	rm *o
