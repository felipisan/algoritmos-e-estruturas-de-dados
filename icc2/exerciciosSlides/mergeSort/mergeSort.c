#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Ideia Geral: 
		- M�todo de ordena��o baseado em divis�o e conquista.
		- Desmembrar o problema em v�rios subproblemas que s�o semelhantes, de menor tamanho,
			resolver os subproblemas recursivamente, e combinar essas solu��es.
		- Assim, dividir, conquistar, combinar!!
		- Exemplo:
			| [8 7 9 2 0 3 5 3] -> primeiro est�gio
			| [8 7 9 2] [0 3 5 3] -> mergeSort(0 a 3)
			| [8 7] [9 2] [0 3 5 3] -> mergeSort(0 a 1)
			| [8] [7] [9 2] [0 3 5 3] -> mergeSort(0 a 0)
			| [7 8] [9 2] [0 3 5 3] -> primeira conquista!!!
			[7 8] | [9 2] [0 3 5 3] -> intercala��o (0 a 1)
			[7 8] | [9] [2] [0 3 5 3] -> mergeSort(2 a 3)
			[7 8] | [2 9] [0 3 5 3] -> intercala��o(2 a 3)
			[2 7 8 9 ] | [0 3 5 3] -> intercala��o(0 a 3)
			...
			   i                   j
			[2 7 8 9 ] | [0 3 3 5] -> intercala��o(4 a 7)
			[0 2 3 3 5 7 8 9]
			   k
			[0 2 3 3 5 7 8 9] | -> intercala��o(0 a 7)
		- Caracter�sticas:
			- para grandes entradas � realizado um grande n�mero de intercala��es; 
				o custo de criar novos vetores � alto.
*/


void imprimeVetor(int* vetor, int inicio, int fim){
	if (fim-inicio <= 100){
		int i;
		for (i=inicio; i<fim; i++)
			printf("%i ", vetor[i]);
	}
	printf("\n");
}

void mergeSort(int* vetor, int inicio, int fim);
void intercala(int* vetor, int inicio, int centro, int fim);

int main(int argc, char* argv[]){
	int geracaoVetor = atoi(argv[1]);
	int tamanhoVetor = atoi(argv[2])+1;
	clock_t inicio, final;
	
	//gera��o dos elementos
	int *vetor = malloc(tamanhoVetor * sizeof(int));
	srand(time(NULL));
	
	int i;
	vetor[0] = -1;
	for (i=1; i<tamanhoVetor; i++){
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

	printf("Merge Gerado: ");
	imprimeVetor(vetor, 0, tamanhoVetor);
	
	inicio = clock();
	mergeSort(vetor, 0, tamanhoVetor-1);
	final = clock();
	
	printf("Merge Ordenado: "); 
	imprimeVetor(vetor, 0, tamanhoVetor);
	printf("Tempo de ordenacao Merge: %lfs\n\n", (final-inicio)/(double)CLOCKS_PER_SEC);
	free(vetor);
	
	return 0;	
}

void mergeSort(int* vetor, int inicio, int fim){
	printf("Vetor: ");imprimeVetor(vetor, inicio, fim+1);
	
	//caso base
	if (fim <= inicio) return;

	//processo de divis�o
	int centro = (int)((inicio+fim)/2.0);
	mergeSort(vetor, inicio, centro);
	mergeSort(vetor, centro+1, fim);

	//processo de conquista
	intercala(vetor, inicio, centro, fim);
	printf("Intercala: ");imprimeVetor(vetor, inicio, fim+1);
}

void intercala(int* vetor, int inicio, int centro, int fim){
	int* vetorAux = (int*) malloc(sizeof(int) * (fim-inicio)+1);

	int i = inicio;	// indice da primeira lista ordenada
	int j = centro+1; //indice da segunda lista ordenada
	int k = 0; //indice do vetor auxiliar

	//compara e intercala os elementos do menor para o maior
	while(i <= centro && j <= fim){
		if (vetor[i] <= vetor[j]){ //verifica qual � o elemento menor entre as duas listas
			vetorAux[k] = vetor[i];
			i++; //proximo elemento da primeira metade
		}
		else{
			vetorAux[k] = vetor[j];
			j++; //proximo elemento da segunda metade
		}
		k++;
	}

	while(i <= centro){//h� elementos na primeira metade ainda?
		vetorAux[k] = vetor[i];
		i++;
		k++;
	}

	while(j <= fim){//h� elementos na segunda metade ainda?
		vetorAux[k] = vetor[j];
		j++;
		k++;
	}

	//atualizando o vetor original com o vetor auxiliar(ordenado)
	for(i = inicio, k = 0; i <= fim; i++,k++)
		vetor[i] = vetorAux[k];
	free(vetorAux);
}

/*
	Fun��o de recorr�ncia:
		Assumimos que todas as opera��es primitivas s�o equivalentes em sua execu��o

	MergeSort: encontrar a fun��o de efici�ncia
		- Opera��o mais relevante: compara��es
		- Definir o caso base (n�o � necess�rio executar novamente, ou seja, vetor unit�rio)
		- recorr�ncia:

	Caso base:				1
	Recorr�ncia:			f(n) = 1 + f(n/2) + f(n/2) + g(n)
	Intercala��o: 			g(n) = 3n + 1 + 1 + (n + 1) = 4n + 3   --> pior caso, n elementos
	
	Ent�o:					f(n) = 1 + f(n/2) + f(n/2) + g(n)
							f(n) = 1 + f(n/2) + f(n/2) + 4n + 3
				(1.vez)		f(n) = 2f(n/2) + 4(n) + 4
				(2.vez)		f(n) = 2f[2f(n/4) + 4(n/2) + 4] + 4n + 4 
								 = 4f(n/4) + 8(n/2) + 8 + 4n + 4 
								 = 4f(n/4) + 8(n/2) + 4n + 12
				(3.vez)		f(n) = 4f[2f(n/8) + 4(n/4) + 4] + 8(n/2) + 4n + 12
								 = 8f(n/8) + 16(n/4) + 16 + 8(n/2) + 4n + 12
								 = 8f(n/8) + 16(n/4) + 8(n/2) + 4n + 28
								 = 8f(n/8) + 4n + 4n + 4n + 28
								 = 8f(n/8) + 12n + 28						* 28 = 16 + 8 + 4
				(k.vez)		f(n) = 2^k.f(n/2^k) + 4kn + somatorio(2^i)
							**observa��o: somatorio(2^i) para i = 2 at� k+1

	Caso base: 				f(1) = 1 
				at�			f(1) = f(n/2^k)
				ent�o		n/2^k = 1  				--> n = 2^k		
				assim, 		k = log2(n)

	Voltando:				f(n) = 2^k.f(n/2^k) + 4kn + somatorio(2^i)
								 = 2^log2(n).f(1) + 4log2(n)n + somatorio(2^i)		***f(1) = 1
								 = 2^log2(n) + 4log2(n)n + somatorio(2^i)
							
							**observa��o: somatorio(2^i) para i = 2 at� log2(n)+1
							**Por Progress�o Geom�trica: 4n-4

				assim, 		f(n) = 2^log2(n) + 4log2(n)n + somatorio(2^i)
								 = n + 4n.log2(n) + 4n - 4
								 = 4n.log2(n) + 5n - 4	
*/

/*
	Exerc�cios:
	1) Implemente o M�todo Merge Sort com a variante de sentinela, ou seja, 
		os dois subvetores a serem ordenados possuem um valor maior que o m�ximo poss�vel, 
		evitando que um dos vetores fique vazio durante a intercala��o.
	2) Implemente um m�todo de ordena��o que utilize MergeSort e InsertionSort conjuntamente. 
		Ao receber uma sequ�ncia de valores, utilize o recurso de divis�o e conquista do MergeSort 
		para obter problemas menores. Contudo, durante o processo de conquista utilize a ideia 
		do Insertion Sort.
		
	Refer�ncias:
		- Cormen, cap�tulo 2.
		- Ascencio, cap�tulo 2.
		- Tenembaum, cap�tulo 6.
		- Sedgewick, cap�tulo 2.
*/