#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(int argc, char *argv[]){ 
    int n, m, num;

    LISTA *lista = lista_criar();

    scanf("%d", &n);

    while(n--){
        scanf("%d", &num);
        ITEM *item = item_criar(num);

        lista_inserir(lista, item);
    }

    scanf("%d", &m);

    while(m--){
        scanf("%d", &num);
        
        int quantidade = busca_rec(lista, num);
        if(quantidade == 0) printf("Busca: %d = Nenhum elemento encontrado na lista.\n", num);
        else if(quantidade == 1) printf("Busca: %d = 1 elemento encontrado na lista.\n", num);
        else printf("Busca: %d = %d elementos encontrados na lista.\n", num, quantidade);
    }

    lista_apagar(&lista);
   	
    return (0);
}


