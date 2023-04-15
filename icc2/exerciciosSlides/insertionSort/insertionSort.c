#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int* vetor, int tamanhoVetor){
	if (tamanhoVetor <= 100){
		int i;
		for (i=0; i<tamanhoVetor; i++)
			printf("%i ", vetor[i]);
	}
	printf("\n");
}

int* insertionSort(int* vetor, int tamanho);

int main(int argc, char* argv[]){
	int geracaoVetor = atoi(argv[1]);
	int tamanhoVetor = atoi(argv[2]);
	clock_t inicio, final;
	
	//gera��o dos elementos
	int *vetor = malloc(tamanhoVetor * sizeof(int));
	srand(time(NULL));
	
	int i;
	for (i=0; i<tamanhoVetor; i++){
		if (geracaoVetor == 0) //aleat�rio
			vetor[i] = rand() % 1000;
		else if (geracaoVetor == 1) //ordenado
			vetor[i] = i;
		else if (geracaoVetor == 2) //invertido
			vetor[i] = tamanhoVetor - i;
		else if (geracaoVetor == 3 && i<=tamanhoVetor/2) //primeira metade ordenada e o restante aleat�rio
			vetor[i] = i;
		else if (geracaoVetor == 3) //primeira metade ordenada e o restante aleat�rio
			vetor[i] = (rand() % 1000) + i;
	}
	
	printf("Insertion Gerado: \n");
	imprimeVetor(vetor, tamanhoVetor);
	
	inicio = clock();
	vetor = insertionSort(vetor, tamanhoVetor);
	final = clock();
	
	printf("\nInsertion Ordenado: \n");
	imprimeVetor(vetor, tamanhoVetor);
	printf("Tempo de ordenacao Insertion: %lfs\n\n", (final-inicio)/(double)CLOCKS_PER_SEC);
	free(vetor);

	return 0;	
}

/*
	Ideia Geral:
		- Percorre um conjunto de elementos da esquerda para a direita 
			e � medida que avan�a vai deixando os elementos � esquerda ordenados, 
			ou seja, o elemento � "inserido" em sua posi��o.
		- Exemplo:
			[| 5 8 7 13 20 22 85 1 4 9] (elementos � esquerda de "|" est�o ordenados)
			[5 | 8 7 13 20 22 85 1 4 9]
			[5 8 | 7 13 20 22 85 1 4 9] (troca 7 por 8)
			[5 7 | 8 13 20 22 85 1 4 9]
			[5 7 8 | 13 20 22 85 1 4 9]
			...
			[5 7 8 13 20 22 85 | 1 4 9] (movendo o valor 1)
				[5 7 8 13 20 22   | 85 4 9]
				[5 7 8 13 20   22 | 85 4 9]
				[  5 7 8 13 20 22 | 85 4 9]
				[1 5 7 8 13 20 22 | 85 4 9]
				[1 5 7 8 13 20 22 85 | 4 9]
			...
			[1 4 5 7 8 9 13 20 22 85 |]
		
		- Caracter�sticas:
			- Eficiente para ordenar um n�mero pequeno de elementos.
			- Abordagem incremental.
			- Altamente dependente da ordem dos valores na entrada, 
				sendo bom para ordenados e parcialmente ordenados.
			- Melhor caso: sequ�ncia previamente ordenada.
			- Pior caso: sequ�ncia previamente ordenada de forma inversa.
*/

int* insertionSort(int* vetor, int tamanho){
	int j; //indica o elemento atual
	for(j = 1; j < tamanho; j++){//o elemento na posi��o 0 n�o precisa analisar
		int chave = vetor[j];
		int i = j - 1; //armazenar a posi��o de an�lise (anterior ao j at� o in�cio do vetor)
		
		//in�cio && valor atual � maior que a chave de an�lise
		while (i >= 0 && vetor[i] > chave){ 
			vetor[i+1] = vetor[i]; //Essa linha significa: vai passando pra frente
			i--;
		} //Esse while vai parar quando o elemento da parte ordenada for menor que a chave, aí a gente coloca
		//a chave depois desse elemento

		//(2 3 4 |(i) 5 (i+1) 6 7 8 9 1 ) 
		
		vetor[i+1] = chave; //posiciona a chave na posi��o correta
		//imprimeVetor(vetor, tamanho);
	}
	
	return vetor;
}

/*
	Exerc�cios:
	1) Implemente o Insertion Sort para ordenar de forma decrescente.
	2) Considere a ordena��o de n n�meros armazenados em um vetor, localizando o primeiro menor 
		elemento e permutando com o elemento contido na primeira posi��o. Em seguida, determine 
		o segundo menor elemento e permute com o elemento contido na segunda posi��o. 
		Continue assim para todos os elementos. (Selection Sort)
	3) Pesquise e implemente o Shell Sort, uma vers�o modificada do Insertion Sort.
	
	Refer�ncias:
		- Cormen, cap�tulo 2.
		- Ascencio, cap�tulo 2.
		- Tenembaum, cap�tulo 6.
		- Sedgewick, cap�tulo 2.
		- Wengrow, cap�tulo 6.
*/