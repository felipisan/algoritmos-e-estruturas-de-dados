#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "item.h"

int main(void) {
	item_t *e;
	fila_t *f = criar_fila();
	
	inserir(f, criar_item(5));
	inserir(f, criar_item(9));
	inserir(f, criar_item(10));
	inserir(f, criar_item(12));
	inserir(f, criar_item(13));
	
	while(!esta_vazia(f)) {
		remover(f, &e);
		printf("%d ", get_valor(e));
		apagar_item(&e);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
