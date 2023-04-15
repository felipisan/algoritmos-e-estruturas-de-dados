#ifndef _PILHA_H
#define _PILHA_H

#include <stdbool.h>
#include "item.h"

#define TAM_PILHA 20

typedef struct pilha pilha_t;

pilha_t *criar_pilha();
bool push(pilha_t *p, item_t *x);
bool pop(pilha_t *p, item_t **x);
bool top(pilha_t *p, item_t **x);
bool isFull(pilha_t *p);
bool isEmpty(pilha_t *p);
void destruir_pilha(pilha_t **p);

#endif