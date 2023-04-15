all: item.o listasequencial.o main.o
	gcc item.o listasequencial.o main.o -o lista -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

listasequencial.o:
	gcc -c listasequencial.c -o listasequencial.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o lista

run:
	./lista
