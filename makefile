CFLAGS = -ansi -pedantic -Wall -O0

program : mazegen.o solver.o main.o
	gcc $(CFLAGS) -o program mazegen.o solver.o main.o
mazegen.o : mazegen.c
	gcc $(CFLAGS) -c mazegen.c
solver.o : solver.c
	gcc $(CFLAGS) -c solver.c
main.o : main.c
	gcc $(CFLAGS) -c main.c
clean :
	rm program mazegen.o solver.o main.o
tempclean :
	rm input.h~ mazegen.c~ solver.c~ main.c~
