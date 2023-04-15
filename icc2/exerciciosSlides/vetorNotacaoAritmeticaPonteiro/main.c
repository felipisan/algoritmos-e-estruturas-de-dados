#include <stdio.h>
#include <stdlib.h>

//Revisão - Vetores

// Gerar duas sequencias aleatorias e fazer soma ponto-a-ponto

int main(){
	int i, vetor1[10], vetor2[10], soma[10];
	
	for (i = 0; i<10; i++){
		*(vetor1 + i) = rand() % 10;
		*(vetor2 + i) = rand() % 10;
		
		//na posicao i de soma, somamos os valores contidos em vetor1 e vetor2 na mesma posição
		*(soma + i) = *(vetor1 + i) + *(vetor2 + i);
		printf("%i + %i = %i\n", *(vetor1 + i), *(vetor2 + i), *(soma + i));
	}
	
	return 0;
}

// Exercícios complementares:
// 1) Apresentar os resultados por vetor ao invés do índice.
// 2) Após realizar o somatório, para um valor no vetor resultante multiplicar pelo seu antecessor, caso ele exista.
// 3) Realizar a soma dos dois vetores de forma invertida do seu índice