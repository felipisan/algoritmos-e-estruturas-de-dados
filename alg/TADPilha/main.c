#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main(void) {
	item_t *x;
	pilha_t *p = criar_pilha();
	push(p, criar_item(2));
	push(p, criar_item(4));
	push(p, criar_item(6));
	push(p, criar_item(8));
	
	while(!isEmpty(p)) {
		pop(p, &x);
		printf("%d ", get_valor(x));
		apagar_item(&x);
	}
	printf("\n");
	
	destruir_pilha(&p);
	
	/*scanf("%d", &x);
	do {
		push(p, x % 2);
		x /= 2;
	} while(x != 0);
	
	while(!isEmpty(p)) {
		pop(p, &x);
		printf("%d", x);
	}
	printf("\n");
	destruir_pilha(&p);*/
	
	return EXIT_SUCCESS;
}
