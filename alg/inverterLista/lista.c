#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lista.h"

typedef struct no_ NO; 

struct no_{
  ITEM *item;
  NO *proximo;
};

struct lista_{ 
  NO *inicio; 
  NO *fim;    
  int tamanho;  
};

#include "lista_inverter.c"

LISTA *lista_criar(void){
  LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
  if(lista != NULL){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
  }

  return (lista);
}

bool lista_inserir(LISTA *lista, ITEM *item){  
  if((!lista_cheia(lista)) && (lista != NULL)){          
    NO *pnovo = (NO *) malloc(sizeof (NO));
    pnovo->item = item;
    pnovo->proximo = NULL;
        
    if (lista->inicio == NULL) lista->inicio = pnovo;  
    else lista->fim->proximo = pnovo;
            
    lista->fim = pnovo;
    lista->tamanho++;
      
    return (true);
  }
    
  return (false);
}

ITEM *lista_remover(LISTA *lista, int chave){
  NO *aux = NULL;
  NO *p = NULL;
  
  ITEM *it;

  if(lista != NULL){
    p = lista->inicio;

    while(p != NULL && (item_get_chave(p->item)) != chave){
      aux = p;
      p = p->proximo;
    }

    if(p != NULL){
      if(p == lista->inicio){
        lista->inicio = p->proximo;
        p->proximo = NULL;
      }

      else{
        aux->proximo = p->proximo;
        p->proximo = NULL;
      }

      if(p == lista->fim) lista->fim = aux;
    
      it = p->item;
      free(p);
      lista->tamanho--;
      return(it);
    }
  }
  return(NULL);

}

bool lista_apagar(LISTA **lista){
  if(*lista != NULL){
    NO *no;
    ITEM *item;

    while((*lista)->inicio != NULL){
        no = (*lista)->inicio;
        item = no->item;
        (*lista)->inicio = (*lista)->inicio->proximo;
        
        item_apagar(&item);
        free(no);
    }
  
    free(*lista);
    *lista = NULL;
    return (true);
  }

  return (false);
}

ITEM *lista_busca(LISTA *lista, int chave){
  NO *aux;

  if(lista != NULL){
    aux = lista->inicio;

    while(aux != NULL){
      if(item_get_chave(aux->item) == chave) return(aux->item);
      aux = aux->proximo;
    }
  }

  return(NULL);
}

int lista_tamanho(LISTA *lista){
  return(lista->tamanho);
}

bool lista_vazia(LISTA *lista){
  if((lista != NULL) && lista->inicio == NULL) return(true);
  
  return(false);
}

bool lista_cheia(LISTA *lista){
  NO *no = (NO*)malloc(sizeof(NO));
  if(no != NULL){
    free(no);
    no = NULL;
    return (false);
  }

  return(true);
}

void lista_imprimir(LISTA *lista){
  NO *p;
  if(lista != NULL){
    p = lista->inicio; 
    
    while(p != NULL){
      printf("[%d]; ", item_get_chave(p->item));
      p = p->proximo;
    } 
    
    printf("\n");
  }
  
  return;
}