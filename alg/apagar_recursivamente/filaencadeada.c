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

#define TAM_FILA 250000

struct fila_ {
	int inicio, fim, total;
	ITEM *itens[TAM_FILA];
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
	if(f->total == TAM_FILA)
		return true;
	return false;
}

bool fila_inserir(FILA *f, ITEM *e) {
	if(!fila_cheia(f)) {
		f->itens[f->fim] = e;
		f->fim = (f->fim + 1) % TAM_FILA;
		f->total++;
		return true;
	}
	return false;
}

ITEM *fila_remover(FILA *f){
	if(!fila_vazia(f)) {
		ITEM *e = f->itens[f->inicio];
		f->inicio = (f->inicio + 1) % TAM_FILA;
		f->total--;
		return e;
	}
	return NULL;
}

void fila_apagar(FILA **fila){
    ITEM *removido = fila_remover(*fila);
    item_apagar(removido);
    fila_apagar(fila);
   	free(*fila);

}

// void fila_apagar(FILA **fila){
// 	if(!fila_vazia(*fila)){
//     	free(fila_remover(*fila));
//         fila_apagar(fila);
//     }
//     free(*fila);
//     *fila = NULL;
// }  

// void fila_apagar(FILA **fila){
//     ITEM *e = fila_remover(*fila);
//     if (e != NULL){
//         //item_apagar(&e): Isso dá segfault. Assumimos que
// 		//o fila_remover terá um free para apagar o item
//         fila_apagar(fila);
//     }
//     free(*fila);
// 	*fila = NULL; 
// }

// void fila_apagar(FILA **f){
// 	if(fila_vazia(*f)) {
// 		free(*f);
// 		*f = NULL;
// 	}
// 	else {
// 		printf("Fila nao esta vazia para ser desalocada.\n");
// 	}
// }