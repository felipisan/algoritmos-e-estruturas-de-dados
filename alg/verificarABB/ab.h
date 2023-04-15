#ifndef ARVORE_BINARIA_H
	#define ARVORE_BINARIA_H
    
    #include "item.h"
    
    #define FILHO_ESQ 0
    #define FILHO_DIR 1

    typedef struct ab_ AB;

    AB *ab_criar(void);
    bool ab_inserir(AB *T, ITEM *item, int lado, int chave);
    bool ab_remover(AB *T, int chave);
    void ab_apagar_arvore(AB **T);
    bool is_abb(AB *T);

#endif