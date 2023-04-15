#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	- Algoritmo: 
		- uma sequ�ncia de passos l�gicos;
		- � correto se, e somente se, para toda inst�ncia de entrada a sa�da � correta
		- diferentes solu��es podem ser implementadas, cada uma com sua complexidade
		- uma solu��o perfeita, pode n�o ser a "melhor solu��o" (solu��es aproximadas)
	
	- Como calcular a efici�ncia de um algoritmo (baseado no tamanho da entrada):
		- tempo de execu��o: mesma m�quina e no mesmo estado
		- contagem de passos:
			- opera��es aritm�ticas e atribui��es;
			- compara��es;
			- resolver um ponteiro ou acesso �s indexa��es;
			- acesso e retorno �s fun��es.
		
	- Vamos fixar estes conceitos por meio da Busca Sequencial e Busca Bin�ria:
		- requisito b�sico para motores de busca na internet, base de dados, etc
	
	- M�todos de Busca:
		- Considerando uma chave e um conjunto de elementos, um m�todo de busca objetiva 
			encontrar a localiza��o correta da chave neste conjunto, se ela existir.
		- Formalmente:
			- Um algoritmo de busca � aquele que aceita um argumento "a" e tenta encontrar 
				o registro cuja chave seja "a". O algoritmo pode retornar o registro inteiro 
				ou um ponteiro para este registro. Se o registro n�o for encontrado retorna-se 
				um registro ou ponteiro nulo.
		- � aplic�vel a diferentes contextos.
		- Consiste em uma estrutura de armazenamento e uma heur�stica de busca:
			- A estrutura de armazenamento pode ser um vetor, uma lista encadeada, uma �rvore 
				ou um grafo.
			- M�todos de busca s�o adequados para determinados tipos de estruturas 
				de armazenamento.
		- Quando a estrutura est� totalmente na Mem�ria RAM utilizamos M�todos Internos.
		- Quando a estrutura est� majoritariamente no Disco utilizamos M�todos Externos.
		
	- Busca Sequencial:
		- Algoritmo mais simples, basicamente sem nenhuma estrat�gia mais elaborada;
		- Percorre o conjunto de elementos comparando a chave com o conte�do atual do conjunto;
		- Retorna a localiza��o do elemento se ele existir;
		- Problem�tico para cen�rios com repeti��o de chaves;
		- Aplic�vel em vetores e listas encadeadas.
*/

/*
	Descri��o: gera valores aleat�rios para um vetor de tamanho quantidade com valores 
		entre minimo e maximo
	Par�metros:
		- int qtdade: tamanho do vetor a ser gerado
		- int minimo: valor minimo que pode ser gerado
		- int maximo: valor maximo que pode ser gerado
	Retorno:
		- int* vetorGerado: vetor de tamanho qtdade preenchido pela fun��o
	Observa��es:
		- vetor n�o tem controle de ordena��o e pode ter valores repetidos.
*/
int* gerarVetor(int qtdade, int minimo, int maximo){
	//srand(time)

	int* vetorGerado = malloc(qtdade * sizeof(int));
	vetorGerado[0] = minimo;
	printf("%i ", vetorGerado[0]);

	int i;
	for (i = 1; i < qtdade; i++){ //gera valores aleat�rios entre minino e maximo
		//rand() % (20 - 11 + 1) + 11
		//vetorGerado[i] = rand() % (maximo-minimo+1) + minimo; //sem ordena��o
		vetorGerado[i] = rand() % (maximo-minimo+1) + minimo + vetorGerado[i-1]; //com ordena��o 
		printf("%i ", vetorGerado[i]);
	}
	
	return vetorGerado;
}

int buscaSequencial_iterativa(int* vetor, int tamanho, int chave);
int buscaSequencial_recursiva(int* vetor, int tamanho, int chave);

int main(int argc, char* argv[]){
	//lendo par�metros iniciais
	int qtdade = atoi(argv[1]);
	int minimo = atoi(argv[2]);
	int maximo = atoi(argv[3]);
	
	//gerando o vetor de dados
	int* vetor = gerarVetor(qtdade, minimo, maximo);
	
	//buscando um valor informado
	int chave;
	printf("\nDigite a chave a ser buscada: ");
	scanf("%i", &chave);
	
	clock_t inicio = clock();
	int posicao = buscaSequencial_iterativa(vetor, qtdade, chave);
	//int posicao = buscaSequencial_recursiva(vetor, qtdade, chave);
	clock_t final = clock();
	double tempo = (final-inicio)/(double)CLOCKS_PER_SEC;
	printf("Tempo de busca: %lf s\n", tempo);
	
	//informando a sa�da ao usu�rio
	if (posicao >= 0 )
		printf("Valor encontrado na posicao %i\n", posicao);
	else
		printf("Valor nao encontrado\n");
	
	//desalocando o vetor din�mico
	free(vetor);
	return 0;
}

/*
	Descri��o: 
		- c�digo pequeno; 
		- basicamente � uma busca por for�a bruta; 
		- fazendo a busca sem nenhuma estrat�gia mais elaborada
	Par�metros:
		- int* vetor: conjunto de dados de busca
		- int tamanho: tamanho do vetor de busca
		- int chave: valor a ser buscado
	Retorno:
		- int (posicao): localiza��o do elemento buscado
	Contagem de opera��es:
		- (A) atribui��o e aritm�ticas
		- (C) compara��o
		- (V) acesso ao vetor
		- (F) acesso ou retorno de fun��o
	N�s consideramos que todas as opera��es levam aproximadamente o tempo de execu��o
	Quando n�s temos fluxos exclusivos, considera-se o pior caso!!!
	
	De termos gerais, a busca Sequencial � totalmente dependente do tamanho "n"
		- quanto mais n aumenta, maior � a quantidade de opera��es realizadas
	- Qual � o melhor caso? o n�mero buscado � o primeiro
	- Qual � o pior caso? o n�mero buscado n�o existe
*/
int buscaSequencial_iterativa(int* vetor, int tamanho, int chave){
	int i;
	for (i = 0; i < tamanho; i++)	//1 vez (A + C); outras vezes (2A + C).(n - 1)
		if (vetor[i] == chave)		//n(V + C) 
			return i;				//F
	return -1;						//F (n�o � executada) -> descartar
	//i++ <==> i = i + 1 (soma e atribui��o) = 2A
	
	/*
		Contagem de opera��es:
		f(n) = A + C + (2A + C).(n - 1) + n(V + C) + F	
		f(n) = A + C + 2An - 2A + Cn - C + Vn + Cn + F
		
		se A = C = V = F = 1
		f(n) = 1 + 1 + 2n - 2 + n - 1 + n + n + 1
		f(n) = 5n

		n = 1: vamos ter 5 opera��es
		n = 2: vamos ter 10 opera��es
		
		Fun��o de efici�ncia: f(n) = 5n
			- Melhor caso (elemento na primeira posi��o): f(1) = 5.1 = 5
			- Pior caso (elemento na �ltima posi��o): f(n) = 5n
			- Caso m�dio (elemento na posi��o n/2): f(n) = 5(n/2)
	*/
}

/*
	Descri��o: 
		- percorre todo o vetor para tentar encontrar o elemento desejado
	Par�metros:
		- int* vetor: dado de entrada
		- int tamanho: indica a parte do vetor a ser percorrida
		- int chave: elemento a ser buscado
	Retorno:
		- int (posicao): posi��o do elemento buscado
*/
int buscaSequencial_recursiva(int* vetor, int tamanho, int chave){
	if (vetor[tamanho-1] == chave) return tamanho-1; //valor encontrado
	if (tamanho == 0) return -1; //valor n�o encontrado; chegamos ao final do vetor
	return buscaSequencial_recursiva(vetor, tamanho-1, chave); //ainda n�o encontramos o valor
	
	/*
		Fun��o de recorr�ncia (considerando somente compara��es):
			(1 vez): f(n) = 2 + f(n-1)
			(2 vez): f(n) = 2 + [2 + f(n-2)] = 4 + f(n-2)
			(3 vez): f(n) = 4 + [2 + f(n-3)] = 6 + f(n-3)
			(k vez): f(n) = 2.k + f(n-k)
		
			f(1) = 1 ent�o n - k = 1, assim: k = n � 1
			voltando: f(n) = 2.(n-1) + f(1)
						   = 2n � 2 + 1 = 2n -1
	*/
}

/*
	Exerc�cios:
	1) Refa�a a contagem da vers�o iterativa considerando somente compara��es
	2) Modifique a Busca Sequencial para casos em que o vetor j� esteja ordenado, 
		acrescentando uma valida��o para interrromper a busca.
	3) Modifique a Busca Sequencial para incorporar o M�todo mover-para-frente. 
		Esta metodologia consiste em reduzir o tempo de busca realocando o item encontrado 
		para o in�cio da lista/vetor para uma pr�xima busca. Assim, elementos mais 
		frequentementes buscados estar�o no in�cio e os menos frequentes estar�o no final. 
		O elemento de retorno deve ser colocado no in�cio e todos os demais (in�cio at� 
		sua posi��o vaga s�o realocados).
	4) Modifique a Busca Sequencial para incorporar o M�todo da transposi��o. 
		Esta metodologia consiste em reduzir o tempo de busca realocando o item encontrado 
		em uma posi��o anterior � sua original, movendo seu antecessor para a posi��o vaga.
		
	Refer�ncias:
		- Tenembaum, cap�tulo 7.
		- Ascencio, cap�tulo 2.
*/