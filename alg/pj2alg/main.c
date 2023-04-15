#include "set.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    SET *A, *B;
    int n_a, n_b, x;
    int op;

    A = set_criar();
    B = set_criar();

    scanf("%d %d", &n_a, &n_b);

    for(int i=0; i<n_a; i++){
        scanf("%d",&x);
        set_inserir(A, x);
    }

    for(int i=0; i<n_b; i++){
        scanf("%d",&x);
        set_inserir(B, x);
    }

    int n_operacoes;
    scanf("%d", &n_operacoes);

    for(int i = 0; i < n_operacoes; i++){
        scanf("%d", &op);

        switch(op){
            case 1: { // INSERCAO de elemento
                int conjunto, num;
                scanf("%d %d", &conjunto, &num);

                if(conjunto == 1) { // INSERCAO no conjunto A
                    set_inserir(A,num);
                }
                else if(conjunto == 2){ // INSERCAO no conjunto B
                    set_inserir(B,num);
                }
                else{
                    printf("Conjunto invalido.\n");
                }
                break;
            }
            case 2: { // REMOCAO de elemento
                int conjunto, num;
                scanf("%d %d", &conjunto, &num);

                if(conjunto == 1) { // REMOCAO no conjunto A
                    set_remover(A,num);
                }
                else if(conjunto == 2){ // REMOCAO no conjunto B
                    set_remover(B,num);
                }
                else{
                    printf("Conjunto invalido.\n");
                }
                break;
            }
            case 3: { // CONSULTA de elemento
                int conjunto, num;
                scanf("%d %d", &conjunto, &num);

                if(conjunto == 1) { // CONSULTA em A
                    if(set_pertence(A,num)) 
                        printf("Pertence.");
                    else
                        printf("Não Pertence.");
                }
                else if(conjunto == 2){ // CONSULTA em B
                    if(set_pertence(B,num)) 
                        printf("Pertence.");
                    else
                        printf("Não Pertence.");
                }
                else{
                    printf("Conjunto invalido.\n");
                }
                break;
            }
            case 4: { // UNIAO (Nlog(N))
                SET *C = set_uniao(A, B);
                set_imprimir(C);
                set_apagar(&C);
                break;
            }
            case 5: { // INSERSECCAO (Nlog(N))
                SET *C = set_interseccao(A, B);
                set_imprimir(C);
                set_apagar(&C);
                break;
            }
            case 6: { // IMPRIMIR conjunto
                int conjunto, num;
                scanf("%d %d", &conjunto, &num);

                if(conjunto == 1) { // CONSULTA em A
                    set_imprimir(A);
                }
                else if(conjunto == 2){ // CONSULTA em B
                    set_imprimir(B);
                }
                else{
                    printf("Conjunto invalido.\n");
                }
                break;
            }
        }
    }

    set_apagar(&A);
    set_apagar(&B);
        
    return 0;
}
