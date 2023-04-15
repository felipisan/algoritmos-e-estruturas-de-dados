#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "aluno.h"

int main(void) {
	aluno_t *a;
	lista_t *l = cria_lista();
	
	a = criar_aluno();
	set_hashedNusp(a, 14);
	set_hashedSenha(a, 20);
	insere(l, a);
	
	a = criar_aluno();
	set_hashedNusp(a, 66);
	set_hashedSenha(a, 21);
	insere(l, a);

	a = criar_aluno();
	set_hashedNusp(a, 77);
	set_hashedSenha(a, 22);
	insere(l, a);

	a = criar_aluno();
	set_hashedNusp(a, 69);
	set_hashedSenha(a, 23);
	insere(l, a);
	
	imprimir(l);
	
	if(esta_na_lista(l, 77)) {
		printf("Esta na lista\n");
	} else {
		printf("Nao esta na lista\n");
	}
	
	remover(l, 69);
	remover(l, 14);
	imprimir(l);	
	
	libera_lista(&l);
	
	return EXIT_SUCCESS;
}