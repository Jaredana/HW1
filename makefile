CFLAGS = -ansi -pedantic -Wall -O0

program : main.o
	gcc $(CFLAGS) -o program main.o
main.o : main.c
	gcc $(CFLAGS) -c main.c
clean :
	rm program main.o
tempclean :
	rm input.h~ main.c~
