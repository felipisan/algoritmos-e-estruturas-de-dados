#include<stdlib.h>
#include<stdio.h>

void shiftToRight(LISTA *lista, int i){
    lista->fim = lista->fim + 1; 

    for (int k = lista->fim; k > i; k--)
        lista->lista[k] = lista->lista[k - 1];
}

bool lista_inserir(LISTA *lista, ITEM *item){
    if(lista == NULL)
        return false;

    //Caso a lista esteja vazia: 
    if(lista->inicio == lista->fim){
        lista->lista[0] = item;
        lista->fim = lista->fim + 1;
        return true;
    }

    //Caso o elemento deva ser inserido entre os elementos que já estão na lista
    //Shifiting necessário
    int i = 0;
    int x = item_get_chave(item);
    while (i < lista->fim){
        if (x <= item_get_chave(lista->lista[i])){
            shiftToRight(lista, i);
            lista->lista[i] = item; 
            return true;
        }
        i++;
    }

    //Caso o elemento seja maior que todos os elementos na lista devemos colocá-lo ao fim
    lista->lista[lista->fim] = item;
    lista->fim = lista->fim + 1;
    return true;
}