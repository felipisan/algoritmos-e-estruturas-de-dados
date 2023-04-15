#include "ab.h"
#include "is_abb.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){ 
    AB *A = ab_criar();

    int n, m;
    int a, b, c;

    scanf("%d", &n);

    while(n--){
        scanf("%d %d %d", &a, &b, &c);

        ITEM *item = item_criar(a);

        ab_inserir(A, item, b, c);
    }

    if(is_abb(A)) printf("É uma ABB.\n");
    else printf("Não é uma ABB.\n");

    ab_apagar_arvore(&A);
    return (0);
}


