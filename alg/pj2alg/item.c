#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item {
	elem info;
};

item_t *criar_item(elem elemento) {
	item_t *item = malloc(sizeof(item_t));
	if(item != NULL) {
		item->info = elemento;
		return item;
	}
	return NULL;
}

void set_valor(item_t *item, elem elemento) {
	if(item != NULL) {
		item->info = elemento;
	}
}

elem get_valor(item_t *item) {
	if(item != NULL) {
		return item->info;
	}
	exit(1); 
}

void apagar_item(item_t **item) {
	if(item != NULL && *item != NULL) {
		free(*item);
		*item = NULL;
	}	
}