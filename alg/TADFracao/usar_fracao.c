#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"


int main(void) {
	fracao_t *f, *f2, *f3;
	erro_t erro;
	
	f = criar_fracao(1, 2, &erro);
	if(erro == memoria) {
		printf("Erro de memoria\n");
		return EXIT_FAILURE;
	}
	
	f2 = criar_fracao(3, 4, &erro);
	if(erro == memoria) {
		printf("Erro de memoria!\n");
		return EXIT_FAILURE;
	}
	
	f3 = somar_fracao(f, f2, &erro);
	if(erro == memoria) {
		printf("Erro de memoria!!\n");
		return EXIT_FAILURE;
	}
	if(erro == ponteiro_invalido) {
		printf("Ponteiro invalido\n");
		return EXIT_FAILURE;
	}
	
	imprimir_fracao(f3);
	
	simplificar_fracao(f3);
	
	imprimir_fracao(f3);
	
	destruir_fracao(f);
	destruir_fracao(f2);
	destruir_fracao(f3);
	
	return EXIT_SUCCESS;
}
