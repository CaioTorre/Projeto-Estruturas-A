maketeste:
	gcc -c matriz.h
	gcc -c lista.h
	gcc -c matriz.c
	gcc -c lista.c
	gcc -c main.c
	gcc -o teste matriz.o lista.o main.o
	./teste
	rm -rf matriz.o
	rm -rf lista.o
	rm -rf main.o

