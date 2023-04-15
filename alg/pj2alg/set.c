#include "set.h"

struct set{
    avl_t *avl;
    int __tam;
};

SET* set_criar(void){
    SET *conjunto;
    
    conjunto = malloc(sizeof(SET));
    conjunto->avl = criar_avl();
    conjunto->__tam = 0;
    return conjunto;
}

bool set_inserir (SET *s, int elemento){
    if(s == NULL) return false;
    s->__tam++;
    inserir_avl(s->avl, elemento);
    return true;
}

bool set_pertence(SET *A, int elemento){
    return buscar_avl(A->avl, elemento);
}

bool set_remover(SET *s, int elemento){
    return remover_avl(s->avl, elemento);
}

void set_apagar(SET **s){
    assert(s != NULL && *s != NULL);
    apagar_avl((*s)->avl);
    free(*s);
    s = NULL;
}

void set_imprimir(SET *s){
    imprimir_avl(s->avl);
}

SET *set_uniao(SET *A, SET *B){
    // Caso ambos os conjuntos sejam vazios
    if(A == NULL && B == NULL) return NULL;
    
    // Caso algum dos conjuntos seja vazio
    if(A == NULL) return B;
    if(B == NULL) return A;

    SET *C = malloc(sizeof(SET));
    C->avl = criar_avl();
    
    //Devemos copiar o maior conjunto para C no caso da união, já que copiar_avl
    // é O(log n), em vez de anexar elemento verificando se ele existe em C (nlog n)
    // (não existe pois acabamos de criar C e não inserimos nada). 
    // Apenas uma otimização bem vinda
    if (A->__tam >= B->__tam){
        copiar_avl(A->avl, C->avl); //log n
        inserir_elementos(B->avl, C->avl); //nlog n
    }
    else{
        copiar_avl(B->avl, C->avl); 
        inserir_elementos(A->avl, C->avl);
    }
    return C;
}

SET *set_interseccao(SET *A, SET *B){
    // Caso ambos os conjuntos sejam vazios
    if(A == NULL && B == NULL) return NULL;
    
    // Caso algum dos conjuntos seja vazio
    if(A == NULL) return B;
    if(B == NULL) return A;

    SET *C = malloc(sizeof(SET));
    C->avl = criar_avl();

    obter_elemrepetidos(A->avl, B->avl, C->avl);
    return C;
}