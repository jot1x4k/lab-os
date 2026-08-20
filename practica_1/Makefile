all: programa1.o programa2.o
	gcc -o programa1 programa1.o
	gcc -o programa2 programa2.o

programa1.o: programa1.c
	gcc -c -o programa1.o programa1.c

programa2.o: programa2.c
	gcc -c -o programa2.o programa2.c

run:
	./programa1 
	./programa2

clean:
	rm -rf *.o programa1 programa2 docs/
