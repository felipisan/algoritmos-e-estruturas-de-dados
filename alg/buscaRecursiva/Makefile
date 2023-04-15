all: item.o lista.o main.o
	gcc item.o lista.o main.o -o lista -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

lista.o:
	gcc -c lista.c -o lista.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o lista

run:
	./lista
