//
//  main.c
//  Trabalho_3_Hora_da_Acao
//
//  Created by Vicenzo D’Arezzo and Felipi Yuri on 18/10/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//----------> ALGORITMOS DE ORDENACAO

    
//   * Bubblesort

int *bubbleSort(int* vetor, int tamanho){
	int i, j;
	int trocou = 0; //Variável que diminui o tempo de execução real do bubbleSort

	for(i = 0; i < tamanho-1; i++){
		for(j = 0; j < tamanho-1-i; j++){ //tamanho-1-i faz reduz o número de comparções do bubble
			if (vetor[j] > vetor[j+1]){
				int aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;		
				trocou = 1;
			}
		}
		if (trocou == 0) //se não houve qualquer troca, o vetor já está ordenado.
			break;
	}
	return vetor;
}	

//   * Mergesort

void sort(int * v, int inicio, int fim, int *contador_troca){
    
    //divide o vetor de parâmetro em duas partes, apontando para o início de cada. A partir disso, realiza a ordenação por intercalação, passando o resultado para o vetor_aux;
    int meio = (inicio + fim)/2;
    int c_1 = inicio, c_2 = meio+1, c_vetor = 0;
    int *vetor_aux = malloc(sizeof(int)*(fim - inicio + 1));
    assert(vetor_aux);
    
    //Faz um laço de repetição até que uma das parcelas acabe primeiro que a outra:
    while(c_1 <= meio && c_2 <= fim){
        if(v[c_1] <= v[c_2]){
            //não há inversão;
            vetor_aux[c_vetor] = v[c_1];
            c_1++;
        }else{
            //há inversão:
            //Nesse momento, para cálcular o número do trocas de par a par que virtualmente são realizadas no método da intercalção, utilizamos a distância entre o primeiro indicador e o meio, pois assim, ao passar o elemento da esquerda para a direita, é justamente ela que representa tal número.
            *contador_troca += meio - c_1 + 1;
            vetor_aux[c_vetor] = v[c_2];
            c_2++;
        }
        c_vetor++;
    }
    
    //copia a metade restante para o vetor auxiliar:
    while(c_1 <= meio){
        vetor_aux[c_vetor] = v[c_1];
        c_1++;
        c_vetor++;
    }
    while (c_2 <= fim) {
        vetor_aux[c_vetor] = v[c_2];
        c_2++;
        c_vetor++;
    }
    
    //passa o vetor auxiliar para a entrada:
    for(int i = inicio, j = 0; i <= fim; i++, j++){
        v[i] = vetor_aux[j];
    }
    
    //liberando o vetor auxiliar:
    free(vetor_aux);
    vetor_aux = NULL;
}
    

void mergeSort(int *vetor, int ini, int fim, int *contador_troca){
    
    //condição de parada da divisão do vetor
    if(ini >= fim) return;
    
    //cálculo do meio:
    int meio =  (int) (ini + fim)/2;
    
    //passo
    mergeSort(vetor, ini, meio, contador_troca);
    mergeSort(vetor, meio+1, fim, contador_troca);
    
    //chamada da função de ordenação base:
    sort(vetor, ini, fim, contador_troca);
}

int main(){
    
    //Loop principal <==> lê até encontrar o 0:
    int tamanho, * vetor = NULL, c_leitura, n_trocas;

    while(scanf("%d ", &tamanho) && tamanho != 0){
        
        n_trocas = 0;
        
        //alocação do vetor
        vetor = (int*) realloc(vetor, tamanho * sizeof(int));
        assert(vetor);
        
        //leitura dos valores, passando-os para o vetor;
        for(c_leitura = 0; c_leitura < tamanho; c_leitura++){
            scanf("%d ", &vetor[c_leitura]);
        }
        
        //Passando o vetor para o algoritmo de ordenação:
        bubbleSort(vetor, tamanho);
        
        
        //Sabendo que Jaques começa, basta checar a paridade no número de trocas para deduzir o vencedor:
        
        n_trocas % 2 == 0 ? printf("Fino\n") : printf("Jaques\n");
    }
    
    //liberando as alocações:
    free(vetor);
    
    return 0;
}
