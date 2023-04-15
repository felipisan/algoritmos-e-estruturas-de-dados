#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct lista_{ 
    ITEM *lista[TAM_MAX];    
    int inicio;  /*inicio da lista*/
    int fim;   /* fim da lista - 1a posição livre para inserção*/
};

// #include "inserir.c"

/*Cria logicamente uma lista, inicialmente vazia*/
LISTA *lista_criar(void){
    /*pré-condição: existir espaço na memória.
    Na implementação estática não há o que verificar*/
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA));     
    lista->inicio = inicial; 
    lista->fim = lista->inicio; /* lista vazia*/
     
    return (lista);
}

void shiftToRight(LISTA *lista, int i){
    lista->fim = lista->fim + 1; 

    for (int k = lista->fim; k > i; k--)
        lista->lista[k] = lista->lista[k - 1];
}

bool lista_inserir(LISTA *lista, ITEM *item){
    if(lista == NULL)
        return false;

    //Caso a lista esteja vazia: 
    if(lista->inicio == lista->fim){
        lista->lista[0] = item;
        lista->fim = lista->fim + 1;
        return true;
    }

    //Caso o elemento deva ser inserido entre os elementos que já estão na lista
    //Shifiting necessário
    int i = 0;
    int x = item_get_chave(item);
    while (i < lista->fim){
        if (x <= item_get_chave(lista->lista[i])){
            shiftToRight(lista, i);
            lista->lista[i] = item; 
            return true;
        }
        i++;
    }

    //Caso o elemento seja maior que todos os elementos na lista devemos colocá-lo ao fim
    lista->lista[lista->fim] = item;
    lista->fim = lista->fim + 1;
    return true;
}

void lista_apagar(LISTA **lista) {
    int i,j;
    if (*lista == NULL) return;
    
    j = lista_tamanho(*lista);
    for(i=0; i<j; i++)
        item_apagar(&(*lista)->lista[i]);
            
    free(*lista);
    *lista = NULL;
}

/*Verifica se a lista está vazia. Retorna TRUE em caso positivo e FALSE
caso contrário*/    
bool lista_vazia(LISTA *lista){
    return(lista->inicio == lista->fim);
}

/*Verifica se a lista está cheia. Retorna TRUE em caso positivo e FALSE
caso contrário*/
bool lista_cheia(LISTA *lista){
    if (lista->fim >= TAM_MAX)
       return(TRUE);
    return(FALSE);
}

int lista_tamanho(LISTA *lista){
    return(lista->fim);
}

void lista_imprimir(LISTA *l){
    for(int i=0; i < l->fim; i++) printf("[%d]; ", item_get_chave(l->lista[i]));  
    printf("\n"); 

    return;
}

/*Procurar um elemento que tenha chave igual a x, começando do início da lista, 
e parando quando a lista terminar ou quando x for encontrado. Retorna erro 
quando a chave não é encontrada. PARA LISTAS NÃO ORDENADAS.
*/
int lista_busca_sequencial(LISTA *l, int x){
    int i;
    
    for(i=0; i<=l->fim; i++) /* ou, melhor, for(i=0; i<=lista->fim-1; i++)*/ 
        if(item_get_chave(l->lista[i]) == x) return(i);
    return(ERRO); /*Não encontrou a chave; */
}

/*Procurar um elemento que tenha chave igual a x, começando do início da lista, 
e parando quando a lista terminar ou quando x for encontrado. Retorna erro 
quando a chave não é encontrada. PARA LISTAS ORDENADAS.
*/
int lista_busca_ordenada(LISTA *l, int x){
    int i=0;
    
    while(item_get_chave(l->lista[i]) < x) i++;
    
    if(item_get_chave(l->lista[i]) == x) return(i);
    
    return(ERRO);
    /*
    for(i=0; i<=l->fim-1;i++)
        if(item_get_chave(l->lista[i]) == x)
            return(i);
        else if (item_get_chave(l->lista[i]) > x)
             return(ERRO); //item não está na lista pois, encontou-se um valor maior que a chave */
    //return(ERRO);/*item não encontrado após percorrer toda a lista*/
}

/*Implementação de Busca Binária. Retorna a posição da chave x na Lista ORDENADA. 
Se x não ocorre retorna erro (ERRO). */
int lista_busca_binaria(LISTA *l, int x){
   
    int inf = 0;
    int sup = l->fim;
    int meio;
 
    while(!(sup < inf)){
       meio = (inf + sup)/2; /* meio recebe o piso (truncamento) da divisão por 2.*/
       if(item_get_chave(l->lista[meio]) == x) return (meio);
       else{
            if(item_get_chave(l->lista[meio]) < x) inf = meio + 1;
            else sup = meio-1;
       }
    }

    return (ERRO); /*retorna erro*/
}

ITEM *lista_busca(LISTA *l, int chave){
    int x = lista_busca_sequencial(l, chave);//pode-se trocar por busca ordenada ou binária
    if( x != ERRO)                      // sem alterar a interface
        return (l->lista[x]);
    
    return (NULL);
}