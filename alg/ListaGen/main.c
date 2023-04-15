#include <stdio.h>
#include <stdlib.h>
#include "listagen.h"
#include "item.h"

int main(void) {
	// lista ((2,3),2)
	no_t *l = concat(sublista(concat(atomo(criar_item(2)), atomo(criar_item(3)))), atomo(criar_item(2)));
	printf("Lista l: ");
	imprimir(l);
	no_t *g = concat(l, atomo(criar_item(10)));
	printf("Lista g: ");
	imprimir(g);
	
	printf("Cauda(g): ");
	imprimir(cauda(g));
	
	printf("Cabeca(g): ");
	int tipo;	
	info_t h = cabeca(g, &tipo);
	if(tipo == 0)
		printf("%d\n", get_valor(h.atomo));
	else
		imprimir(h.sublista);	
	
	libera(g);
	
}