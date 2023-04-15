#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main (void){
    FILA *fila=NULL;

    int n;
    ITEM *it;

    fila = fila_criar();

    //qtd de números
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
       fila_inserir(fila, item_criar(i));

    fila_apagar(&fila);

    if (fila == NULL)
      printf("Fila vazia!\n");

    return(0);
}
