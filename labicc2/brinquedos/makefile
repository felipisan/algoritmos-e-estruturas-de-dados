all: main.o
	gcc main.o -o main -std=c99 -Wall
	

main.o:
	gcc -c main.c -o main.o

run:
	./main < entrada.in

clean:
	rm *.o main
