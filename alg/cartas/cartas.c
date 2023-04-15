/*
* Nome: Felipi Yuri Santos
* NUSP: 11917292
* 
* Curso: SCC0202 - Algoritmos e Estruturas de Dados I
* Prof. Marcelo Manzato
*/


void cartas(int n){
    FILA *f = fila_criar();

    int i = 1;

    while (i <= n){
        fila_inserir(f, item_criar(i));
        i++;
    }

    printf("Discarded cards: ");
    
	i = 0;
	while(i < n - 1){
        ITEM *item = fila_remover(f);
		if (i == n - 2)
			printf("%d", item_get_chave(item));
		else
        	printf("%d, ", item_get_chave(item));
        item_apagar(&item);
        fila_inserir(f, fila_remover(f));
		i++;
    }
    
	printf("\n");
	ITEM *item = fila_remover(f);
    printf("Remaining card: %d\n", item_get_chave(item));
    item_apagar(&item);

	fila_remover(f);
	fila_apagar(&f);
}