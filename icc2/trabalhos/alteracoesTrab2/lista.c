#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lista.h"

typedef struct no no_t;

struct no {
	aluno_t *info;
	no_t *prox;
};

struct lista {
	no_t *ini, *fim;
	int total;
};

lista_t *cria_lista() {
	lista_t *l = (lista_t *)malloc(sizeof(lista_t));
	assert(l != NULL);
	l->ini = NULL;
	l->fim = NULL;
	l->total = 0;
	return l;
}

void libera_lista(lista_t **l) {
	assert(*l != NULL);
	no_t *p;
	
	p = (*l)->ini;
	while(p != NULL) {
		(*l)->ini = (*l)->ini->prox;
		apagar_aluno(&(p->info));
		free(p);
		p = (*l)->ini;
	}
	(*l)->fim = NULL;
	
	free(*l);
	*l = NULL;
}

void insere(lista_t *l, aluno_t *a) {
	assert(l != NULL);
	no_t *p = (no_t *) malloc(sizeof(no_t));
	assert(p != NULL);
	p->info = a;
	p->prox = NULL;
	if(l->ini == NULL) { //lista esta vazia
		l->ini = p;
	} else { //lista com pelo menos um elemento
		l->fim->prox = p;
	}
	l->fim = p;
	l->total++;
}

int tamanho(lista_t *l) {
	assert(l != NULL);
	return l->total;
}

bool esta_na_lista(lista_t *l, int nusp) {
	assert(l != NULL);
	no_t *p = l->ini;
	while(p != NULL) {
		if(get_nusp(p->info) == nusp)
			return true;
		p = p->prox;
	}
	return false;
}

void imprimir(lista_t *l) {
	assert(l != NULL);
	no_t *p = l->ini;
	
	while(p != NULL) {
		printf("%d ", get_nusp(p->info));
		p = p->prox;
	}
	printf("\n");
}

aluno_t *varrer_por_nusp(lista_t *l, int nusp){
	assert(l != NULL);
	no_t *p = l->ini;
	
	while (p != NULL){
		if (get_nusp(p->info) == nusp)
			return p->info;
		p = p->prox;
	}
	return NULL;
}

void remover(lista_t *l, int nusp) {
	assert(l != NULL);
	no_t *p = l->ini;
	no_t *ant = NULL;
	
	while(p != NULL && get_nusp(p->info) != nusp) {
		ant = p;
		p = p->prox;
	}
	
	//1o. caso: elemento nao encontrado
	if(p == NULL) {
		return;
	}
	
	//2o. caso: elemento encontrado eh o primeiro da lista
	if(ant == NULL) {
		l->ini = p->prox;				
		if(l->total == 1)
			l->fim = NULL;
	} else if(p == l->fim) { //3o. caso: elemento encontrado eh o ultimo da lista
		ant->prox = NULL;
		l->fim = ant;
	} else { //4o. caso: elemento encontrado esta no meio da lista
		ant->prox = p->prox;
	}
	
	apagar_aluno(&(p->info));
	free(p);		
	l->total--;
}



