/*
* Nome: Felipi Yuri Santos
* NUSP: 11917292
* 
* Curso: SCC0202 - Algoritmos e Estruturas de Dados I
* Prof. Marcelo Manzato
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila.h"

struct fila_ {
	int inicio, fim, total;
	ITEM *itens[51];
};

FILA *fila_criar() {
	FILA *f = (FILA *)malloc(sizeof(FILA));
	assert(f != NULL);
	f->inicio = 0;
	f->fim = 0;
	f->total = 0;
	return f;
}


bool fila_vazia(FILA *f){
	assert(f != NULL);
	if(f->total == 0)
		return true;
	return false;
}

bool fila_cheia(FILA *f){
	assert(f != NULL);
	if(f->total == 51)
		return true;
	return false;
}

bool fila_inserir(FILA *f, ITEM *e) {
	if(!fila_cheia(f)) {
		f->itens[f->fim] = e;
		f->fim = (f->fim + 1) % 51;
		f->total++;
		return true;
	}
	return false;
}

ITEM *fila_remover(FILA *f){
	if(!fila_vazia(f)) {
		ITEM *e = f->itens[f->inicio];
		f->inicio = (f->inicio + 1) % 51;
		f->total--;
		return e;
	}
	return NULL;
}

void fila_apagar(FILA **f){
	if(fila_vazia(*f)) {
		free(*f);
		*f = NULL;
	}
	else {
		printf("Fila nao esta vazia para ser desalocada.\n");
	}
}



void cartas(int n){
    FILA *f = fila_criar();

    int i = 1;

    while (i <= n){
        fila_inserir(f, item_criar(i));
        i++;
    }

    printf("Discarded cards: ");
    
	i = 0;
	while(i < n - 1){
        ITEM *item = fila_remover(f);
		if (i == n - 2)
			printf("%d", item_get_chave(item));
		else
        	printf("%d, ", item_get_chave(item));
        item_apagar(&item);
        fila_inserir(f, fila_remover(f));
		i++;
    }
    
	printf("\n");
	ITEM *item = fila_remover(f);
    printf("Remaining card: %d\n", item_get_chave(item));
    item_apagar(&item);

	fila_remover(f);
	fila_apagar(&f);
}