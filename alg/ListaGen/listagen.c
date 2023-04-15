#include "listagen.h"

struct _no {
	int tipo;
	info_t info;
	no_t *prox;
};

void libera(no_t  *p) {
	no_t *aux;
	while(p != NULL) {
		aux = p;
		p = p->prox;
		if(aux->tipo == 0) {
			apagar_item(&(aux->info.atomo));
		} else {
			libera(aux->info.sublista);
		}
		free(aux);
	}
}

no_t *atomo(item_t *x) {
	no_t *p = (no_t *)malloc(sizeof(no_t));
	p->tipo = 0;
	p->info.atomo = x;
	p->prox = NULL;
	return p;
}

no_t *sublista(no_t *sublista) {
	no_t *p = (no_t *)malloc(sizeof(no_t));
	p->tipo = 1;
	p->info.sublista = sublista;
	p->prox = NULL;
	return p;
}

no_t *concat(no_t *p, no_t *q) {
	assert(p != NULL);
	
	no_t *aux = p;
	
	while(p->prox != NULL) {
		p = p->prox;
	}
	p->prox = q;
	return aux;
}

info_t cabeca(no_t *p, int *tipo) {
	assert(p != NULL);
	*tipo = p->tipo;
	return p->info;
}

no_t *cauda(no_t *p) {
	assert(p != NULL);
	return p->prox;
}

void imprime(no_t *p) {
	printf("[");
	while(p != NULL) {
		if(p->tipo == 0)
			printf("%d", get_valor(p->info.atomo));
		else 
			imprime(p->info.sublista);
		if(p->prox != NULL)
			printf(",");
		p = p->prox;
	}
	printf("]");
}

void imprimir(no_t *p) {
	imprime(p);
	printf("\n");
}