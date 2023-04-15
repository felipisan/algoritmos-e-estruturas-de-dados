#include <stdio.h>
#include <stdlib.h>

typedef struct _aluno aluno_t;

aluno_t *criar_aluno();
void apagar_aluno(aluno_t **a);

void set_nusp(aluno_t *a, int nusp);
int get_nusp(aluno_t *a);

void set_hashedSenha(aluno_t *a, int senha);
int get_hashedSenha(aluno_t *a);

void set_notas(aluno_t *a, double *notas);
double *get_notas(aluno_t *a);

