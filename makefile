makeproject:
	gcc -c matriz.h
	gcc -c matriz.c
	gcc -c lista.h
	gcc -c lista.c
	gcc -c main.c
	gcc -o proj matriz.o lista.o main.o
	./proj
	rm -rf matriz.o
	rm -rf lista.o
	rm -rf main.o
