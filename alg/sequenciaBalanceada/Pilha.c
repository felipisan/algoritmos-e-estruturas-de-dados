#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Pilha.h"
#include "item.h"

struct pilha {
	int topo;
	ITEM *itens[TAM];
};

PILHA *pilha_criar() {
	PILHA *p = (PILHA *)malloc(sizeof(PILHA));
	assert(p != NULL);
	p->topo = -1;
	return p;
}

bool pilha_empilhar(PILHA *pilha, ITEM *x) {
	assert(pilha != NULL);
	if(!pilha_cheia(pilha)) {
		pilha->topo += 1;
		pilha->itens[pilha->topo] = x;
		return true;
	}
	return false;
}

ITEM* pilha_topo(PILHA* pilha){
	assert(pilha != NULL);
	if(!pilha_vazia(pilha)) {
		return pilha->itens[pilha->topo];
	}
	return false;
}

bool pilha_cheia(PILHA *pilha) {
	assert(pilha != NULL);
	if(pilha->topo == TAM - 1) {
		return true; 
	}
	return false;
}

bool pilha_vazia(PILHA *pilha) {
	assert(pilha != NULL);
	if(pilha->topo == -1) {
		return true; 
	}
	return false;
}

void pilha_apagar(PILHA **pilha) {
	if(*pilha != NULL) {
		free(*pilha);
		*pilha = NULL;
	}
}

ITEM* pilha_desempilhar(PILHA *pilha) {
	assert(pilha != NULL);
	if(!pilha_vazia(pilha)){
		return pilha->itens[pilha->topo--];
	}
}

