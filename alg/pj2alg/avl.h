#ifndef _AVL_H
#define _AVL_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "item.h"

    typedef struct no no_t;
    typedef struct avl avl_t;

    avl_t *criar_avl();
    bool esta_vazia(avl_t *arv);
    void inserir_avl(avl_t *arv, elem x);
    void apagar_avl(avl_t *arv);
    bool remover_avl(avl_t *arv, elem x);
    bool buscar_avl(avl_t *arv, elem x);
    void imprimir_avl(avl_t *arv);
    void copiar_avl(avl_t *src, avl_t *dest);
    void inserir_elementos(avl_t *src, avl_t *dest);
    void obter_elemrepetidos(avl_t *A, avl_t *B, avl_t *dest);

#endif