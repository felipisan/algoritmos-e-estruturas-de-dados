#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item_ {
	char chave;
};

ITEM *item_criar(char chave) {
	ITEM *p = (ITEM *) malloc(sizeof(ITEM));
	if(p != NULL) {
		p->chave = chave;
		return p;
	}
	return NULL;
}

bool item_set_chave(ITEM *item, char chave){
	if(item != NULL) {
		item->chave = chave;
		return true;
	}
	return false;
}

char item_get_chave(ITEM *item) {
	if(item != NULL) {
		return item->chave;
	}
	exit(1); 
}

bool item_apagar(ITEM **item){
	if(*item != NULL) {
		free(*item);
		*item = NULL;
		return true;
	}
	return false;
}

// void item_imprimir(ITEM *item){

// }