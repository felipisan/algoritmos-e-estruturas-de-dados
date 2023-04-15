#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>
#include "aluno.h"

typedef struct lista lista_t; 

lista_t *cria_lista();
void libera_lista(lista_t **l);
void insere(lista_t *l, aluno_t *a);
int tamanho(lista_t *l);
bool esta_na_lista(lista_t *l, int hashed_nusp);
void imprimir(lista_t *l);
void remover(lista_t *l, int hashed_nusp);

#endif