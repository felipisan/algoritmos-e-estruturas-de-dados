#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Métodos de ordenação:
		- O objetivo dos algoritmos de ordenação é rearranjar os itens de forma que as chaves são 
			ordenadas de acordo com alguma regra bem-definida 
			(geralmente numericamente ou alfabeticamente).
		- Este rearranjo consiste em chaves menores dispostas anteriormente a chaves maiores 
			nos índices do arranjo.
		
	Introdução à Análise da Complexidade para Algoritmos:
		- O tempo de execução do pior caso estabelece um limite superior para o 
			tempo de execução para qualquer entrada. Isso nos dá uma garantia de 
			que o algoritmo nunca demorará mais do que este tempo.
		- Para alguns algoritmos, o pior caso é o mais frequente.
		- Muitas vezes, o caso médio é quase tão ruim quanto o pior caso.
		- É a taxa de crescimento ou ordem de crescimento que realmente nos interessa 
			(termo de maior grandeza).
*/

void imprimeVetor(int* vetor, int tamanhoVetor){
	if (tamanhoVetor <= 100){
		int i;
		for (i=0; i<tamanhoVetor; i++)
			printf("%i ", vetor[i]);
	}
	printf("\n");
}

int* bubbleSort_iterativo(int* vetor, int tamanho);

int main(int argc, char* argv[]){
	int geracaoVetor = atoi(argv[1]);
	int tamanhoVetor = atoi(argv[2]);
	clock_t inicio, final;
	
	//geração dos elementos
	int *vetor = malloc(tamanhoVetor * sizeof(int));
	srand(time(NULL));
	
	int i;
	for (i=0; i<tamanhoVetor; i++){
		if (geracaoVetor == 0) //aleatório
			vetor[i] = rand() % 1000;
		else if (geracaoVetor == 1) //ordenado
			vetor[i] = i;
		else if (geracaoVetor == 2) //invertido
			vetor[i] = tamanhoVetor - i;
		else if (geracaoVetor == 3 && i<=tamanhoVetor/2) //primeira metade ordenada e o restante aleatório
			vetor[i] = i;
		else if (geracaoVetor == 3) //primeira metade ordenada e o restante aleatório
			vetor[i] = (rand() % 1000) + i;
	}

	printf("Bubble Gerado: \n");
	imprimeVetor(vetor, tamanhoVetor);
	
	inicio = clock();
	bubbleSort_iterativo(vetor, tamanhoVetor);
	final = clock();
	
	printf("\nBubble Ordenado: \n"); 
	imprimeVetor(vetor, tamanhoVetor);
	printf("Tempo de ordenacao Bubble: %lfs\n\n", (final-inicio)/(double)CLOCKS_PER_SEC);
	free(vetor);
	
	return 0;	
}

/*
	Ideia Geral:
		- Método de ordenação que busca confirmar os maiores valores,
			tendo certeza da localização do último elemento para o primeiro.
		- Cada elemento é comparado ao seu sucessor, trocando os elementos de acordo 
			com uma condição.
		- Exemplo:
			[9 2 5 1 0 6 |]
			[2 5 1 0 6 | 9]
			[2 1 0 5 | 6 9]
			[1 0 2 | 5 6 9]
			[0 1 | 2 5 6 9]
			[0 | 1 2 5 6 9]
			[| 0 1 2 5 6 9]
		- Exemplo (i = 0):
			[9 2 5 1 0 6] -> j = 0
			[2 9 5 1 0 6] -> j = 1
			[2 5 9 1 0 6] -> j = 2
			[2 5 1 9 0 6] -> j = 3
			[2 5 1 0 9 6] -> j = 4
			[2 5 1 0 6 9] -> j = 5 (somente o 9 está ordenado)
		- Exemplo (i = 1):
			[2 5 1 0 6 9] -> j = 0
			[2 5 1 0 6 9] -> j = 1
			[2 1 5 0 6 9] -> j = 2
			[2 1 0 5 6 9] -> j = 3
			[2 1 0 5 6 9] -> j = 4 (somente o 6 e 9 está ordenado)
*/

int* bubbleSort_iterativo(int* vetor, int tamanho){
	int i, j;
	for(i = 0; i < tamanho-1; i++){
		for(j = 0; j < tamanho-1-i; j++){ //tamanho-1-i ao invés de tamanho-1 garante uma melhora
			if (vetor[j] > vetor[j+1]){
				int aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;		
			}
		}
		//imprimeVetor(vetor, tamanho);
	}
	
	return vetor;
}	
/*
	- Características:
		- Melhor caso: vetor previamente ordenado (impede as trocas)
		- Pior caso: vetor previamente ordenado inversamente (if será executado sempre)
		
	- Exercícios:
	1) Implemente o BubbleSort de forma invertida, ou seja, garanta que o elemento ordenado	
		seja o menor
	2) Execute e compare os diversos cenários para o Bubble (ordenado, inversamente ordenado,
		aleatório e parcialmente ordenado)
*/

/*
	Referências:
		- Ascencio, capítulo 2.
		- Tenembaum, capítulo 6.
		- Wengrow, capítulo 4.
*/