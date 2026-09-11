# Taller: Creacion de procesos

all: compilar

compilar: procesos.o
	gcc -o procesos procesos.o

procesos.o:
	gcc -Wall -c -o procesos.o procesos.c

clean:
	rm -f *.o procesos