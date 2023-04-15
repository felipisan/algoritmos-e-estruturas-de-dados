#ifndef LISTAGEN_H
#define LISTAGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listagen.h"
#include "item.h"

typedef union _info info_t;
typedef struct _no no_t;

union _info {
	item_t *atomo;
	no_t *sublista;
};

void libera(no_t  *p);
no_t *atomo(item_t *x);
no_t *sublista(no_t *sublista);
no_t *concat(no_t *p, no_t *q);
info_t cabeca(no_t *p, int *tipo);
no_t *cauda(no_t *p);
void imprimir(no_t *p);


#endif