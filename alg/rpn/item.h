#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdbool.h>

	typedef struct item_ ITEM;

	ITEM *item_criar(float chave);
	bool item_apagar(ITEM **item);
	void item_imprimir(ITEM *item);
	float item_get_chave(ITEM *item);
	bool item_set_chave(ITEM *item, float chave);

#endif
