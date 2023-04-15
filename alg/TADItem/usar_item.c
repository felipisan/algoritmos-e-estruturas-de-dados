#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int main(void) {
	item_t *e = criar_item('a');
	printf("%c\n", get_valor(e));
	apagar_item(&e);
	
	return EXIT_SUCCESS;
}
