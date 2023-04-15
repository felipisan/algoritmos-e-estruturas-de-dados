
cc = gcc
flags = -Wall -std=c99

fracao: math.o fracao.o usar_fracao.o
	$(cc) $(flags) -o fracao *.o
	
math.o: math.h
	$(cc) $(flags) -c math.c

fracao.o: fracao.h math.h
	$(cc) $(flags) -c fracao.c
	
usar_fracao.o: usar_fracao.c fracao.h
	$(cc) $(flags) -c usar_fracao.c
	
clean: 
	rm *.o