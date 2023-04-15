#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila.h"

struct fila {
	int inicio, fim, total;
	item_t *itens[TAM_FILA];
};

fila_t *criar_fila() {
	fila_t *f = (fila_t *)malloc(sizeof(fila_t));
	assert(f != NULL);
	f->inicio = 0;
	f->fim = 0;
	f->total = 0;
	return f;
}

bool esta_cheia(fila_t *f) {
	assert(f != NULL);
	if(f->total == TAM_FILA)
		return true;
	return false;
}

bool esta_vazia(fila_t *f) {
	assert(f != NULL);
	if(f->total == 0)
		return true;
	return false;
}

bool inserir(fila_t *f, item_t *e) {
	if(!esta_cheia(f)) {
		f->itens[f->fim] = e;
		f->fim = (f->fim + 1) % TAM_FILA;
		f->total++;
		return true;
	}
	return false;
}

bool remover(fila_t *f, item_t **e) {
	if(!esta_vazia(f)) {
		*e = f->itens[f->inicio];
		f->inicio = (f->inicio + 1) % TAM_FILA;
		f->total--;
		return true;
	}
	return false;
}

void destruir_fila(fila_t **f) {
	if(esta_vazia(*f)) {
		free(*f);
		*f = NULL;
	}
	else {
		printf("Fila nao esta vazia para ser desalocada.\n");
	}
	
}