#ifndef _FILA_H
#define _FILA_H

#include <stdbool.h>
#include "item.h"

#define TAM_FILA 10

typedef struct fila fila_t;

fila_t *criar_fila();
bool esta_cheia(fila_t *f);
bool esta_vazia(fila_t *f);
bool inserir(fila_t *f, item_t *e);
bool remover(fila_t *f, item_t **e);
void destruir_fila(fila_t **f);

#endif