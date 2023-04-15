// No "avl.h" já está todas as outras bibliotecas
#include "avl.h"

// Estruturas necessárias para Árvore AVL
struct no{
	item_t *info;
	no_t *esq, *dir;
	int conf_balanceamento;
};

struct avl{
	no_t *raiz;
};


// Criação e extra
avl_t *criar_avl(){
	avl_t *avl = malloc(sizeof(avl_t));
	avl->raiz = NULL;
	return avl;
}
bool esta_vazia(avl_t *avl){
	assert(avl != NULL);
	if(avl->raiz == NULL) return true;
	return false;
}

// Rotações necessárias
no_t *rotacao_EE(no_t *raiz){
	no_t *aux = raiz->dir;
	raiz->dir = aux->esq;
	aux->esq = raiz;
	return aux;
}

no_t *rotacao_DD(no_t *raiz){
	no_t *aux = raiz->esq;
	raiz->esq = aux->dir;
	aux->dir = raiz;
	return aux;
}


// Inserção na AVL
no_t *inserir_raiz(no_t *raiz, elem x, int *flag){
	if(raiz == NULL){
		raiz = (no_t*)malloc(sizeof(no_t));
		raiz->dir = NULL;
		raiz->esq = NULL;
		raiz->conf_balanceamento = 0;
		raiz->info = criar_item(x);
		(*flag) = 0;
	}
	else{
		if(get_valor(raiz->info)> x)
		{
			raiz->esq = inserir_raiz(raiz->esq, x , flag);
			if(raiz->conf_balanceamento == 0 && (*flag) == 0)raiz->conf_balanceamento = 1;
			else if(raiz->conf_balanceamento == -1 && (*flag) == 0)
			{
				(*flag) = 1;
				raiz->conf_balanceamento = 0;
			}
			else if(raiz->conf_balanceamento == 1 && (*flag) == 0)
			{
				if(raiz->esq->conf_balanceamento == 1)
				{
					raiz = rotacao_DD(raiz);
					raiz->conf_balanceamento = 0;
					raiz->dir->conf_balanceamento = 0;
				}
				else
				{
					raiz->esq = rotacao_EE(raiz->esq);
					raiz = rotacao_DD(raiz);
					if(raiz->conf_balanceamento == -1)
					{
						raiz->conf_balanceamento = 0;
						raiz->esq->conf_balanceamento = 1;
						raiz->dir->conf_balanceamento = 0;
					}
					else if(raiz->conf_balanceamento == 0)
					{
						raiz->conf_balanceamento = 0;
						raiz->esq->conf_balanceamento = 0;
						raiz->dir->conf_balanceamento = 0;
					}
					else
					{
						raiz->conf_balanceamento = 0;
						raiz->esq->conf_balanceamento = 0;
						raiz->dir->conf_balanceamento = -1;
					}
				}
				(*flag) = 1;
			}
		}
		else if(get_valor(raiz->info) < x){
			raiz->dir = inserir_raiz(raiz->dir, x, flag);
			if(raiz->conf_balanceamento == 0 && (*flag) == 0) raiz->conf_balanceamento = -1;
			else if(raiz->conf_balanceamento == 1 && (*flag) == 0){
				(*flag) = 1;
				raiz->conf_balanceamento = 0;
			}
			else if(raiz->conf_balanceamento == -1 && (*flag) == 0){
				if(raiz->dir->conf_balanceamento == -1){
					raiz = rotacao_EE(raiz);
					raiz->conf_balanceamento = 0;
					raiz->esq->conf_balanceamento = 0;
				}
				else{
					raiz->dir = rotacao_DD(raiz->dir);
					raiz = rotacao_EE(raiz);
					if(raiz->conf_balanceamento == -1)
					{
						raiz->conf_balanceamento = 0;
						raiz->esq->conf_balanceamento = 1;
						raiz->dir->conf_balanceamento = 0;

					}
					else if(raiz->conf_balanceamento == 0)
					{
						raiz->conf_balanceamento = 0;
						raiz->esq->conf_balanceamento = 0;
						raiz->dir->conf_balanceamento = 0;
					}
					else
					{
						raiz->conf_balanceamento = 0;
						raiz->esq->conf_balanceamento = 0;
						raiz->dir->conf_balanceamento = -1;
					}
				}
				(*flag) = 1;
			}
		}
		else
		{
			printf("ja existe");
		}
	}
	return raiz;
}

void inserir_avl(avl_t *avl, elem x){
	assert(avl != NULL);
	int flag;
	avl->raiz = inserir_raiz(avl->raiz, x, &flag);
}

// Apagar AVL
void apagar_raiz(no_t *raiz){
	if(raiz != NULL) {
		apagar_raiz(raiz->esq);
		apagar_raiz(raiz->dir);
		apagar_item(&(raiz->info));
		free(raiz);
	}
}

void apagar_avl(avl_t *avl){
	apagar_raiz(avl->raiz);
	free(avl);
}


// Remover nó
no_t *conf_balanceamento_esq(no_t *raiz, int *flag){
	if(raiz->conf_balanceamento == 1 && (*flag) == 1)raiz->conf_balanceamento = 0;
	else if(raiz->conf_balanceamento == 0 && (*flag) == 1)
	{
		(*flag) = 0;
		raiz->conf_balanceamento = -1;
	}
	else if(raiz->conf_balanceamento == -1 && (*flag) == 1)
	{
		if(raiz->dir->conf_balanceamento <= 0)
		{
			raiz = rotacao_EE(raiz);
			if(raiz->conf_balanceamento == 0)
			{
				raiz->esq->conf_balanceamento = -1;
				raiz->conf_balanceamento = 1;
				(*flag = 0);
			}
			else{
				raiz->esq->conf_balanceamento = 0;
				raiz->conf_balanceamento = 0;
			}
		}
		else
		{
			raiz->dir = rotacao_DD(raiz->esq);
			raiz = rotacao_EE(raiz);
			if(raiz->conf_balanceamento == 1)
			{
				raiz->esq->conf_balanceamento = 0;
				raiz->dir->conf_balanceamento = -1;
			}
			else if(raiz->conf_balanceamento == 0)
			{
				raiz->esq->conf_balanceamento = 0;
				raiz->dir->conf_balanceamento = 0;
			}
			else
			{
				raiz->esq->conf_balanceamento = 1;
				raiz->dir->conf_balanceamento = 0;
			}
			raiz->conf_balanceamento = 0;
		}
	}
	return raiz;
}
no_t *conf_balanceamento_dir(no_t *raiz, int *flag){
	if(raiz->conf_balanceamento == -1 && (*flag) == 1)raiz->conf_balanceamento = 0;
	else if(raiz->conf_balanceamento == 0 && (*flag) == 1)
	{
		(*flag) = 0;
		raiz->conf_balanceamento = 1;
	}
	else if(raiz->conf_balanceamento == 1 && (*flag) == 1)
	{
		if(raiz->esq->conf_balanceamento >= 0)
		{
			raiz = rotacao_DD(raiz);
			if(raiz->conf_balanceamento == 0)
			{
				raiz->dir->conf_balanceamento = 1;
				raiz->conf_balanceamento = -1;
				(*flag) = 0;
			}
			else{
				raiz->dir->conf_balanceamento = 0;
				raiz->conf_balanceamento = 0;
			}
		}
		else
		{
			raiz->dir = rotacao_EE(raiz->esq);
			raiz = rotacao_DD(raiz);
			if(raiz->conf_balanceamento == 1)
			{
				raiz->esq->conf_balanceamento = 0;
				raiz->dir->conf_balanceamento = -1;
			}
			else if(raiz->conf_balanceamento == 0)
			{
				raiz->esq->conf_balanceamento = 0;
				raiz->dir->conf_balanceamento = 0;
			}
			else
			{
				raiz->esq->conf_balanceamento = 1;
				raiz->dir->conf_balanceamento = 0;
			}
			raiz->conf_balanceamento = 0;
		}
	}
	return raiz;
}
no_t *buscar_raiz_remove(no_t *raiz, no_t *chave, int *flag){
	if(raiz->dir != NULL){
		raiz->dir = buscar_raiz_remove(raiz->dir, chave, flag);
		if((*flag) == 1){
			raiz = conf_balanceamento_dir(raiz, flag);
		}
	}
	else{
		no_t *aux = raiz;
		chave->info = raiz->info;
		raiz = raiz->esq;
		free(aux);
		aux = NULL;
		(*flag) = 1;
	}

	return raiz;
}
no_t *remover_no(no_t *raiz, elem x, int *flag){
	no_t *aux;

	if(raiz == NULL){
		printf("Item não encontrado\n");
		// flag = 0; // precisa disso?
	}
	else if(get_valor(raiz->info)> x){
		raiz->esq = remover_no(raiz->esq, x, flag);
		if((*flag) == 1){
			raiz = conf_balanceamento_esq(raiz, flag);
		}
	}
	else if(get_valor(raiz->info) < x){
		raiz->dir = remover_no(raiz->dir, x, flag);
		if((*flag) == 1){
			raiz = conf_balanceamento_dir(raiz, flag);
		}
	}
	else{
		if(raiz->dir == NULL){
			aux = raiz;
			raiz = raiz->esq;
			free(aux);
			(*flag) = 1;
		}
		else if(raiz->esq == NULL){
			aux = raiz;
			raiz = raiz->dir;
			free(aux);
			(*flag) = 1;
		}
		else{
			raiz->esq = buscar_raiz_remove(raiz->esq, raiz, flag);
			if((*flag) == 1)
				raiz = conf_balanceamento_esq(raiz, flag);
		}
	}
	return raiz;
}
bool remover_avl(avl_t *avl, elem x){
	if(avl == NULL) return false;
	int flag = 0;
	avl->raiz = remover_no(avl->raiz, x, &flag);
	return true;
}

// Buscar nó
bool buscar_raiz(no_t *raiz, elem x){
	if(raiz == NULL) return false;
	
	if(get_valor(raiz->info) == x) 
		return true;
	
	if(get_valor(raiz->info) < x) 
		return buscar_raiz(raiz->dir, x);
	else 
		return buscar_raiz(raiz->esq, x);
	// return true;
}
bool buscar_avl(avl_t *avl, elem x){
	return buscar_raiz(avl->raiz, x);
}

// Imprimir AVL em ordem (esq->raiz->dir)
void imprimir_raiz(no_t *raiz){
	if(raiz == NULL) return;
	
	imprimir_raiz(raiz->esq);
	printf("%d, ", get_valor(raiz->info));
	imprimir_raiz(raiz->dir);
}
void imprimir_avl(avl_t *avl){
	if(avl == NULL) return;
    
	imprimir_raiz(avl->raiz);
	printf("\n");
}

void copiar_no(no_t *raizSrc, avl_t *dest){
	if (raizSrc == NULL) return;

	copiar_no(raizSrc->esq, dest);
	inserir_avl(dest, get_valor(raizSrc->info));
	copiar_no(raizSrc->dir, dest);
}

void copiar_avl(avl_t *src, avl_t *dest){
	if (src == NULL || dest == NULL) return;
	copiar_no(src->raiz, dest);
}


void anexar_nos(no_t *raizSrc, avl_t *dest){
	if (raizSrc == NULL) return;

	anexar_nos(raizSrc->esq, dest);
	if(buscar_avl(dest, get_valor(raizSrc->info)) == false)
		inserir_avl(dest, get_valor(raizSrc->info));
	anexar_nos(raizSrc->dir, dest);
}

void inserir_elementos(avl_t *src, avl_t *dest){
	if (src == NULL || dest == NULL) return;
	anexar_nos(src->raiz, dest);
}

void obter_nosrepetidos(no_t *raizA, avl_t *B, avl_t *dest){
	if (raizA == NULL) return;

	obter_nosrepetidos(raizA->esq, B, dest);
	if (buscar_avl(B, get_valor(raizA->info)) == true)
		inserir_avl(dest, get_valor(raizA->info));
	obter_nosrepetidos(raizA->dir, B, dest);
}

void obter_elemrepetidos(avl_t *A, avl_t *B, avl_t *dest){
	if (A == NULL || B == NULL) return;
	obter_nosrepetidos(A->raiz, B, dest);
}