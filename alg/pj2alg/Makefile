all: item.o avl.o set.o main.o
	gcc item.o avl.o set.o main.o -o main -std=c99 -Wall -Werror

item.o:
	gcc -c item.c -o item.o

avl.o:
	gcc -c avl.c -o avl.o

set.o:
	gcc -c set.c -o set.o

main.o:
	gcc -c main.c -o main.o
	
clean:
	rm *.o main

run:
	valgrind -q ./main