#include <stdio.h>
#include <stdlib.h>

int *bubbleSort(int* vetor, int tamanho){
	int i, j;
	int trocou = 0;

	for(i = 0; i < tamanho-1; i++){
		for(j = 0; j < tamanho-1-i; j++){
			if (vetor[j] > vetor[j+1]){
				int aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;		
				trocou = 1;
			}
		}
		if (trocou == 0)
			break;
	}
	return vetor;
}	