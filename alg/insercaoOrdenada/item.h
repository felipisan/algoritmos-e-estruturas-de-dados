#ifndef ITEM_H
	#define ITEM_H

	#define TRUE 1 /*define valor booleano – não existe na linguagem C*/
	#define FALSE 0
	#define boolean int /*define um tipo booleano*/
	#define ERRO -32000

	#include <stdbool.h>

	typedef struct item_ ITEM;

	ITEM *item_criar(int chave);
	bool item_apagar(ITEM **item);
	void item_imprimir(ITEM *item);
	int item_get_chave(ITEM *item);
	bool item_set_chave(ITEM *item, int chave);

#endif
