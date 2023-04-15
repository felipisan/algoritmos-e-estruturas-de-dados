#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main (void){
     LISTA *lista;
     int i, num, n;

     lista = lista_criar();

     //qtd de números/itens
     scanf("%d", &n);

     for(int i=0; i<n; i++){
          scanf("%d", &num);
          lista_inserir(lista, item_criar(num));
     }

     lista_imprimir(lista);

     lista_apagar(&lista);

     return(0);
}
