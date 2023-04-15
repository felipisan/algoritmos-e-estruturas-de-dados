#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct _aluno {
	int hashed_nusp;
	int hashed_senha;
	double *notas; 
};

aluno_t *criar_aluno() {
	aluno_t *p = (aluno_t *)malloc(sizeof(aluno_t));
	if(p != NULL) {
		return p;
	}
	return NULL;
}

void apagar_aluno(aluno_t **a) {
	if(a != NULL && *a != NULL) {
		free(*a);
		*a = NULL;
	}	
}

void set_hashedNusp(aluno_t *a, int hashed_nusp) {
	if(a != NULL) {
		a->hashed_nusp = hashed_nusp;
	}
}

int get_hashedNusp(aluno_t *a) {
	if(a != NULL) {
		return a->hashed_nusp;
	}
	exit(1); 
}

void set_hashedSenha(aluno_t *a, int senha){
	if (a != NULL){
		a->hashed_senha = senha;
	}
}

int get_hashedSenha(aluno_t *a){
	if (a != NULL)
		return a->hashed_senha;
}

void set_notas(aluno_t *a, double *notas){
	if (a != NULL){
		a->notas = notas;
	}
}

double *get_notas(aluno_t *a){
	if (a != NULL){
		return a->notas;
	}
}


