#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct _aluno {
	int nusp;
	int hashed_senha;
	double *notas; 
};

aluno_t *criar_aluno() {
	aluno_t *p = (aluno_t *) malloc(sizeof(aluno_t));
	if(p != NULL) {
		return p;
	}
	return NULL;
}

void set_nusp(aluno_t *a, int nusp) {
	if(a != NULL) {
		a->nusp = nusp;
	}
}

int get_nusp(aluno_t *a) {
	if(a != NULL) {
		return a->nusp;
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
	return -1;
}

void set_notas(aluno_t *a, double input_notas[]){
	double *notas = (double *) malloc(4 * sizeof(double));
	for (int i = 0; i < 4; i++){
		notas[i] = input_notas[i];
	}
	if (a != NULL){
		a->notas = notas;
	}
}

double *get_notas(aluno_t *a){
	if (a != NULL){
		return a->notas;
	}
	return NULL;
}

void clear_notas(aluno_t *a){
	if (a != NULL){
		free(a->notas);
		a->notas = NULL;
	}
}

void apagar_aluno(aluno_t **a) {
	if(a != NULL && *a != NULL) {
		clear_notas(*a);
		free(*a);
		*a = NULL;
	}	
}
