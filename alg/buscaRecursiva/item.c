#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item_ {
	int valor;
};

ITEM *item_criar(int x) {
	ITEM *p = (ITEM *) malloc(sizeof(ITEM));
	if(p != NULL) {
		p->valor = x;
		return p;
	}
	return NULL;
}

bool item_set_chave(ITEM *item, int chave){
	if(item != NULL) {
		item->valor = chave;
	}
}

int item_get_chave(ITEM *item){
	if(item != NULL) {
		return item->valor;
	}
	exit(1); 
}

bool item_apagar(ITEM **item){
	if(item != NULL && *item != NULL) {
		free(*item);
		*item = NULL;
	}	
}