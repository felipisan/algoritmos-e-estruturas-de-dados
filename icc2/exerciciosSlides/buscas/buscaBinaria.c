#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*		
	- Busca Bin�ria:
		- Mais eficiente que a Busca Sequencial por reduzir o espa�o de busca;
		- Divide o conjunto de entrada atual em duas metades sucessivamente, 
			comparando a chave com o elemento central ou realizando a busca novamente;
		- Requer que o conjunto de dados esteja ordenado.
		- Aplic�vel em estruturas como vetor, pois utiliza os �ndices durante a busca 
			por serem inteiros positivos.
*/

int* fernandoSort(int* vetor, int tamanho){
	int j;
	for(j = 1; j < tamanho; j++){
		int chave = vetor[j];
		int i = j - 1;
		while (i >= 0 && vetor[i] > chave){
			vetor[i+1] = vetor[i];
			i--;
		}
		vetor[i+1] = chave;
		
		int k;
		for (k=0; k<tamanho; k++) printf("%i ", vetor[k]);
		printf("- analise posicao %i\n", j);
	}
	printf("Vetor Ordenado!!\n\n");
	return vetor;
}

int buscaBinaria_recursiva(int* vetor, int inicio, int fim, int chave);
int buscaBinaria_iterativa(int* vetor, int inicio, int fim, int chave);

int main(void){
	//gera��o dos elementos
	int tamanhoVetor = 10;
	int *vetor = malloc(tamanhoVetor * sizeof(int));
	srand(time(NULL));
	
	int i;
	for (i=0; i<tamanhoVetor; i++){
		vetor[i] = rand() % 1000;
		printf("%i ", vetor[i]);
	}
	vetor = fernandoSort(vetor, tamanhoVetor);
	
	//leitura do elemento de busca
	int chave;
	printf("\nDigite a chave a ser buscada no vetor: ");
	scanf("%d", &chave);

	//busca do elemento desejado
	//int posicao = buscaBinaria_recursiva(vetor, 0, tamanhoVetor-1, chave);
	int posicao = buscaBinaria_iterativa(vetor, 0, tamanhoVetor-1, chave);
	
	//resultado
	printf("A chave %i esta na posicao %i\n", chave, posicao);
	free(vetor);
	
	return 0;	
}

/*
	Descri��o: 
		- busca bin�ria realiza a divis�o do vetor em partes (metades) baseando-se 
			no c�lculo do elemento central
		- especifica um espa�o de busca, ou seja, regi�es reduzidas como entrada da fun��o
	Par�metros:
		- int* vetor: vetor de entrada
		- int inicio: posi��o do primeiro elemento do vetor
		- int fim: posica��o do �ltimo elemento do vetor
		- int chave: elemento a ser buscado		
	Retorno:
		- int (posicao): posi��o do elemento buscado
	Requisitos:
		- o vetor deve estar ordenado
*/ 
int buscaBinaria_recursiva(int* vetor, int inicio, int fim, int chave){
	int centro = (int)((inicio+fim)/2);
	
	if (chave == vetor[centro])
		return centro; 
	if (inicio > fim) 
		return -1; 
	if (chave < vetor[centro]) 
		return buscaBinaria_recursiva(vetor, inicio, centro-1, chave);
	if (chave > vetor[centro])
		return buscaBinaria_recursiva(vetor, centro+1, fim, chave); 
}





	/*
		Quantas compara��es (opera��o mais importante na busca)? 4 compara��es
			f(n) = 4 + f(n/2^1)					//4.1 + f(n/2^1)
				 = 4 + [4 + f(n/2^2)]			//4.2 + f(n/2^2)
			     = 4 + [4 + [4 + f(n/2^3)]]]	//4.3 + f(n/2^3)
			....
			     = 4.k + f(n/2^k)

		Matematicamente, n�s temos que n/2^k = 1 --> n = 2^k --> k = log2(n)
			f(n) = 4.log2(n) + 1
	*/	

/*
	Descri��o: busca bin�ria realiza a divis�o do vetor em partes (metades) baseando-se 
		no c�lculo do elemento central
		- requisito: o vetor precisa estar ordenado
		- especifica um espa�o de busca, ou seja, regi�es reduzidas como entrada da fun��o
	Par�metros:
		- int* vetor: vetor de entrada
		- int inicio: posi��o do primeiro elemento do vetor
		- int fim: posica��o do �ltimo elemento do vetor
		- int chave: elemento a ser buscado
	Retorno:
		- int (posicao): posi��o do elemento buscado
*/
int buscaBinaria_iterativa(int* vetor, int inicio, int fim, int chave){
	while(inicio <= fim){ //log n
		int centro = (int)((inicio+fim)/2);
		printf("valor inicial %i; valor final %i; valor central %i; inicio %i; final %i; centro %i\n", 
			vetor[inicio], vetor[fim], vetor[centro], inicio, fim, centro);
	
		if (chave == vetor[centro]) 
			return centro; //valor encontrado 
		if (chave < vetor[centro]) //se o n�mero existir estar� na primeira metade
			fim = centro - 1;
		if (chave > vetor[centro]) //se o n�mero existir estar� na segunda metade
			inicio = centro + 1;
	}
	return -1;//valor n�o encontrado
}

/*
	- Considerando: 
		Busca Sequencial (Bs)
		Busca Binaria (Bb)
	- Ent�o: Bs(n) < Bb(log n) + T(?)

	O diferencial � a quantidade de vezes que eu fa�o a busca!!! (k)
		Bs(n).k > Bb(log n).k + T(?) 
	--> quando k � "pequeno" � mais vantajoso usar Busca Sequencial
	--> quando k � "grande" � mais vantajoso usar Busca Bin�ria

	Observa��o:
	- Precisamos estudar o cen�rio por completo!!!
	- Quando olhamos os m�todos separadamente, sabemos que Busca Bin�ria � menos complexa
	- Quando incluimos a ordena��o, a Busca Sequencial passa a ser menos complexa
	- Quando vamos executar este cen�rio k vezes, depende do valor de k

	Exemplo:
		f(n) = n + 3
		g(n) = n + 4
		Qual � melhor? f(n)
			-> n = 1 -> f(1) = 4; g(1) = 5 --- 20%
			-> n = 100000 -> f(100000) = 100003; g(100000) = 100004 -- 0.000..%
*/


/*
	Exercícios:
	1) Melhore o c�digo disponibilizado da Busca Bin�ria Recursiva. 
		Defina a nova fun��o de recorr�ncia.
	2) Encontre o melhor e pior caso para a Busca Bin�ria, assim como o caso m�dio.
	3) Execute as implementa��es da Busca Sequencial e Bin�ria para diferentes tamanhos de entrada. 
		Crie um gr�fico que mostre o tempo de execu��o.
	4) Considerando a mesma ideia do exerc�cio 3, crie um gr�fico em termos da fun��o 
		de recorr�ncia.
	5) Implemente uma fun��o de busca que possua chaves no formato de caracteres.
		
	Refer�ncias:
		- Tenembaum, cap�tulo 7.
		- Ascencio, cap�tulo 2.
*/