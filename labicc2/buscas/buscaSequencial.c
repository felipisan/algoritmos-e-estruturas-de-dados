//
//  main.c
//  Exe_2_WallE
//
//  Created by Vicenzo D’Arezzo on 23/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int comparador(const void *el_1, const void *el_2) {
    // retorno > 0 : maior ; == 0 : iguais ; < 0 menor.
    return ( *((int*) el_1) - *((int*) el_2) );
}

bool busca_sequencial(int *vetor, int busca, int n){
    //Percorre todo o vetor, comparando o contéudo de cada elemento ao parâmetro. Ao encontrar, retorna verdadeiro; caso contrário, retorna falso ao encerrar o laço de repetição.
    for(int i = 0; i < n; i++){
        if(vetor[i] ==  busca) return true;
    }
    return false;
}

int main() {
    
    //leitura dos números:
    int n_n;
    scanf("%d\n", &n_n);
    int * vetor_numeros = malloc(n_n * sizeof(int));
    assert(vetor_numeros);

    for(int i = 0; i < n_n; i++){
        scanf(" %d", &vetor_numeros[i]);
    }
    //ordenação do vetor:
    qsort(vetor_numeros, n_n, sizeof(int), comparador);
    
    //leitura buscas:
    int n_b;
    scanf(" %d\n", &n_b);
    int * vetor_buscas = malloc(n_b * sizeof(int));
    assert(vetor_buscas);
    for(int i = 0; i < n_b; i++){
        scanf(" %d", &vetor_buscas[i]);
    }
    
    //busca:
    for(int i = 0; i < n_b; i++){
        bool saida = busca_sequencial(vetor_numeros, vetor_buscas[i], n_n);
        saida ? printf("Encontrou\n") : printf("Nao encontrou\n");
    }
    
    //libera cada vetor:
    free(vetor_numeros);
    free(vetor_buscas);
    
    return 0;
}
