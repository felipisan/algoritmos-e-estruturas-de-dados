#include <stdio.h>
#include <stdlib.h>
#include "ab.h"
#include "is_abb.c"

typedef struct no_ NO; 

struct no_{
    ITEM *item;
    NO *esq;
    NO *dir;
    };

struct ab_{ 
    NO *raiz;    
    int profundidade;
};

AB *ab_criar(){
    AB* nova_ab = (AB *) malloc(sizeof(AB));
    nova_ab->raiz = NULL;
    nova_ab->profundidade = -1;
    return nova_ab;
}

NO *busca(NO *raiz, int x) {
	if(raiz == NULL) {
		return NULL;
	}
	
	if(item_get_chave(raiz->item) == x) {
		return raiz;
	}
	
	NO *p = busca(raiz->esq, x);
	if(p == NULL)
		p = busca(raiz->dir, x);
	
	return p;
}

NO *buscar(AB *A, int x) {
	return busca(A->raiz, x);
}

bool ab_inserir(AB *T, ITEM *item, int lado, int chave){
    
	NO *p = (NO *)malloc(sizeof(NO));
	p->esq = NULL;
	p->dir = NULL;
	p->item = item;
	
    if (T->raiz == NULL){
        T->raiz = p;
    }
    else{
        NO *aux = buscar(T, chave);
        if (lado == FILHO_ESQ){
            if(aux != NULL && aux->esq == NULL)
                aux->esq = p;
            else {
                item_apagar(&(p->item));
                free(p);
                return false;
            }
        }
        else{
            if(aux != NULL && aux->dir == NULL)
                aux->dir = p;
            else {
                item_apagar(&(p->item));
                free(p);
                return false;
            }
        }
    }
	return true;
}

NO *busca_pai(NO *raiz, int x) {
	if(raiz == NULL)
		return NULL;
	
	if(raiz->esq != NULL && item_get_chave(raiz->esq->item) == x)
		return raiz;
	
	if(raiz->dir != NULL && item_get_chave(raiz->dir->item) == x)
		return raiz;
	
	NO *p = busca_pai(raiz->esq, x);
	if(p == NULL)
		p = busca_pai(raiz->dir, x);
	
	return p;
}

NO *buscar_pai(AB *A, int x) {
	return busca_pai(A->raiz, x);
}

bool ab_remover(AB *T, int chave){
    NO *pai, *p;
	int eh_esq;
	
	// primeira parte: encontrar p e pai
	if(T->raiz != NULL && item_get_chave(T->raiz->item) == chave) {
		pai = NULL;
		p = T->raiz;
	} else {
		pai = buscar_pai(T, chave);
		if(pai != NULL) {
			if(pai->esq != NULL && item_get_chave(pai->esq->item) == chave) {
				p = pai->esq;
				eh_esq = 1;
			} else {
				p = pai->dir;
				eh_esq = 0;
			}
		} else {
			p = NULL;
		}
	}
	
	// segunda parte: remover o no
	if(p == NULL) {
		return false;
	}
	if(p->esq == NULL && p->dir == NULL) {
		if(pai == NULL) {
			T->raiz = NULL;
		} else {
			if(eh_esq)
				pai->esq = NULL;
			else 
				pai->dir = NULL;
		}
		item_apagar(&(p->item));
		free(p);
	} else {
		if(p->esq != NULL) {
			item_set_chave(p->item, item_get_chave(p->esq->item));
			item_set_chave(p->esq->item, chave);
		} else {
			item_set_chave(p->item, item_get_chave(p->dir->item));
			item_set_chave(p->dir->item, chave);
		}
		return ab_remover(T, chave);
	}
	return true;
}

void ab_apagar_no(NO *raiz){
    if(raiz != NULL) {
		ab_apagar_no(raiz->esq);
		ab_apagar_no(raiz->dir);
		item_apagar(&(raiz->item));
		free(raiz);
	}
}

void ab_apagar_arvore(AB **T){
	ab_apagar_no((*T)->raiz);
	free(*T);
}
