#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"
#include "math.h"

struct frac {
	int num, den;
};

/*typedef int fracao_t[2];*/

fracao_t *criar_fracao(int num, int den, erro_t *erro) {
	*erro = sem_erro;
	if(den == 0) {
		*erro = div_zero;
		return NULL;
	}
	
	fracao_t *f = (fracao_t *)malloc(sizeof(fracao_t));
	if(f == NULL) {
		*erro = memoria;
		return NULL;
	}
	f->num = num;
	f->den = den;
	
	return f;
}

void imprimir_fracao(fracao_t *f) {
	if(f != NULL) {
		printf("%d/%d\n", f->num, f->den);
	}
}

void destruir_fracao(fracao_t *f) {
	if(f != NULL) {
		free(f);
	}
}

fracao_t *somar_fracao(fracao_t *f1, fracao_t *f2, erro_t *erro) {
	*erro = sem_erro;
	if(f1 == NULL || f2 == NULL) {
		*erro = ponteiro_invalido;
		return NULL;
	}
	
	fracao_t *res = (fracao_t *)malloc(sizeof(fracao_t));
	if(res == NULL) {
		*erro = memoria;
		return NULL;
	}
	
	res->den = f1->den * f2->den;
	res->num = (f1->den * f2->num) + (f2->den * f1->num);
	
	return res;
}

void simplificar_fracao(fracao_t *f) {
	if(f != NULL) {
		int m = mdc(f->num, f->den);
		f->num /= m;
		f->den /= m;
	}
}




