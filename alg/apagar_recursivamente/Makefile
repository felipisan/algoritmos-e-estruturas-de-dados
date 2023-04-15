all: item.o filaencadeada.o main.o
	gcc item.o filaencadeada.o main.o -o fila -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

filaencadeada.o:
	gcc -c filaencadeada.c -o filaencadeada.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o fila

run:
	./fila
