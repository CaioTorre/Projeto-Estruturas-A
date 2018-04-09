maketeste:
	gcc -c matriz.c
	gcc -c teste.c
	gcc -o teste matriz.o teste.o
	./teste
	rm -rf *.o
	rm -rf teste
