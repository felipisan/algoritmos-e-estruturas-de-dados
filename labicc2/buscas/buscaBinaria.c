#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comparador(const void *el_1, const void *el_2) {
    // retorno > 0 : maior ; == 0 : iguais ; < 0 menor.
    return ( *((int*) el_1) - *((int*) el_2) );
}

/*
* Método de busca binário usando recursão. Complexidade: 4log_2(n) + 1. 
* Ou seja, temos: O(log n). 
* -
* -
* Parâmetros:
* (int *) vetor: recebe um ponteiro para inteiro qualquer como argumento
* (int) posIni: índice do vetor onde começaremos a análise do vetor para busca
* (int) posFinal: índice do vetor onde a busca é interrompida
* (int) chave: o valor que desejamos saber onde está no vetor
*/
int buscaBinaria_recursiva(int* vetor, int posIni, int posFinal, int chave){
	int centro = (int)((posIni+posFinal)/2);

	// A busca é bem sucedida quando encontramos o valor, que necessariamente está no centro
	if (chave == vetor[centro]) 
		return centro; 

	//Busca malsucedida
	if (posIni > posFinal)
		return -1; 

	//Dividindo pela metade, já que o valor buscado é menor que a mediana do vetor
	if (chave < vetor[centro])  
		return buscaBinaria_recursiva(vetor, posIni, centro-1, chave);
	// if (chave > vetor[centro])
		return buscaBinaria_recursiva(vetor, centro+1, posFinal, chave); 

}

int main(void){
    int k;
    scanf("%d\n", &k);

    int *vetor_numeros = malloc(k * sizeof(int));
    
    for(int i = 0; i < k; i++){
        scanf(" %d", &vetor_numeros[i]);
    }

    //ordenação do vetor:
    qsort(vetor_numeros, k, sizeof(int), comparador);  

    //leitura buscas:
    int q;
    scanf(" %d\n", &q);
    int * vetor_buscas = malloc(q * sizeof(int));

    for(int i = 0; i < q; i++){
        scanf(" %d", &vetor_buscas[i]);
    }
    
    for(int i = 0; i < q; i++){
        int saida = buscaBinaria_recursiva(vetor_numeros, 0, k - 1, vetor_buscas[i]);
        if (saida == -1)
			printf("Nao encontrou\n");
		else
			printf("Encontrou\n");
    }

    free(vetor_numeros);
    free(vetor_buscas);
    
    return 0;
}