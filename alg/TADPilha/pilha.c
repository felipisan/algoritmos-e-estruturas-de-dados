#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pilha.h"
#include "item.h"

struct pilha {
	int topo;
	item_t *itens[TAM_PILHA];
};

pilha_t *criar_pilha() {
	pilha_t *p = (pilha_t *)malloc(sizeof(pilha_t));
	assert(p != NULL);
	p->topo = -1;
	return p;
}

bool push(pilha_t *p, item_t *x) {
	assert(p != NULL);
	if(!isFull(p)) {
		p->topo += 1;
		p->itens[p->topo] = x;
		return true;
	}
	return false;
}

bool pop(pilha_t *p, item_t **x) {
	if(top(p, x)) {
		p->topo -= 1;
		return true;
	}
	
	return false;
}

bool top(pilha_t *p, item_t **x) {
	assert(p != NULL);
	if(!isEmpty(p)) {
		*x = p->itens[p->topo];
		return true;
	}
	return false;
}

bool isFull(pilha_t *p) {
	assert(p != NULL);
	if(p->topo == TAM_PILHA - 1) {
		return true; 
	}
	return false;
}

bool isEmpty(pilha_t *p) {
	assert(p != NULL);
	if(p->topo == -1) {
		return true; 
	}
	return false;
}

void destruir_pilha(pilha_t **p) {
	if(*p != NULL) {
		free(*p);
		*p = NULL;
	}
}
