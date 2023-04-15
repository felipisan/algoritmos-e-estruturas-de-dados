//
//  main.c
//  Trabalho 6 - Heap
//
//  Created by Vicenzo D’Arezzo and Felipi Yuri Santos on 24/11/22.
//


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct heap{
    int * vetor;
    int capacidade;
    int tamanho_heap;
}heap_t;

heap_t * heap_criar(int n);
bool heap_inserir(int key, heap_t * heap);
void heap_apagar(heap_t ** a);
void heapifyMax(int* vetor, int pai, int tamanho);
void heapSort(int* vetor, int tamanho);

// MAIN ----------------------------------------------------------

int main(void) {
    int n;
    scanf("%d", &n);

    int *entrada = (int*) malloc((n + 1) * sizeof(int));

    int i;
    for(i = 1; i < n + 1; i++){
        scanf("%d", &entrada[i]);
        getchar();
    }

    heapSort(entrada, n);
    
    for(i = 1; i < n + 1; i++){
        printf("%d ", entrada[i]);
    }
    
    free(entrada);

    return 0;
}

//IMPLEMENTAÇÃO 1 ------------------------------------------------

//cria o resgistro da heap e aloca seu vetor interno.
heap_t *heap_criar(int n){
    heap_t *h = (heap_t *) malloc(sizeof(heap_t));
    assert(h);
    h->vetor = (int *) calloc(n, sizeof(int));
    assert(h);
    h->capacidade = n;
    h->tamanho_heap = 0;
    return h;
}

//Função utilizada pelo bubbleUp, retorna o pai do índice k.
int consTutelar(int k){
    if (k % 2 == 0)
        return k / 2 - 1;
    else
        return (k - 1) / 2;
}


//Analisa a antecedência de um elemento, verificando e realizando as trocas necessárias.
void bubbleUp(int id, int *vetor){
    int pai = consTutelar(id);
    int aux;
    
    //condição de parada:
    if(pai < 0) return;
    
    //caso pai menor que filho, troca os elementos e chama a recursão para o pai.
    if(vetor[pai] < vetor[id]){
        aux = vetor[pai];
        vetor[pai] = vetor[id];
        vetor[id] = aux;
        bubbleUp(pai, vetor);
    }
}


//Insere um elemento no vetor da heap, mantendo sua lei.
bool heap_inserir(int key, heap_t * heap){
    //verifica se esta cheia
    if(heap->capacidade < heap->tamanho_heap)
        return false;
    
    int indice = heap->tamanho_heap;
    heap->tamanho_heap += 1;
    heap->vetor[indice] = key;
    
    //percorre a altura da árvore realizando as trocas caso necessário
    bubbleUp(indice, heap->vetor);
    return true;
}

//apaga o registro heap e seu vetor interno.
void heap_apagar (heap_t ** h){
    assert(*h);
    free((*h)->vetor);
    free(*h);
    *h = NULL;
}

//IMPLEMENTAÇÃO 2 -----------------------------------------------

//Verifica a descendência de um elemento, verificando e realizando as trocas necessárias.
void heapifyMax(int* vetor, int pai, int tamanho){
	//verificar os filhos do "pai", se ferir a condição trocar o maior filho com o pai
	int filho = pai*2;//filho da esquerda
	//filho da direita = filho+1; pai*2+1

	if (filho > tamanho) return;

	//printf("Pai: %i. Esquerda %i.\n", vetor[pai], vetor[filho]);
	if (vetor[filho] > vetor[pai] || (filho+1 <= tamanho && vetor[filho+1] > vetor[pai])){
		//1 - existe o filho da direita
		//2 - o filho da direita é maior que o filho da esquerda
		if (filho+1 <= tamanho && vetor[filho+1] > vetor[filho])
			filho = filho+1;
		//se falso, filho deve ser trocado com o pai (padrão é trocar com o filho da esquerda)

		//troca o pai com o maior filho
		//***se o maior filho é o da esquerda, ele já se encontra em "filho"
		int aux = vetor[pai];
		vetor[pai] = vetor[filho];
		vetor[filho] = aux;

		//atualizar possíveis "netos" restantes
		heapifyMax(vetor, filho, tamanho);
	}
}


//Recebe uma Heap e realiza uma ordenação dentro do vetor heap.
void heapSort(int* vetor, int tamanho){
	//construção do MaxHeap
	int ultimoPai = (int)tamanho/2.0;
	int i;
	for (i = ultimoPai; i>=1; i--) //somente nós que possuem filhos!
		heapifyMax(vetor, i, tamanho);
	
	//processo de ordenação
	while (tamanho > 1){//tamanho == 1 (vetor unitário) 
		//maior elemento está sempre na raiz vetor[1]; colocamos o maior valor na última posição
		int maior = vetor[1];
		vetor[1] = vetor[tamanho];
		vetor[tamanho] = maior;

		tamanho--; //reduzimos o tamanho do Heap
		heapifyMax(vetor, 1, tamanho);//verificamos a consistência do Heap para o nó-raiz!
		//com a troca, o maior elemento não está na raiz!
	}
}
