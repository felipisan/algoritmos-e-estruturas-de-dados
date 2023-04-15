all: aluno.o lista.o main.o
	gcc -g aluno.o lista.o main.o -o ex -std=c99 -Wall

aluno.o:
	gcc -c aluno.c -o aluno.o

lista.o:
	gcc -c lista.c -o lista.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o ex

run:
	./ex
