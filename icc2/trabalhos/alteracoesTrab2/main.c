/*
* Nome: Felipi Yuri Santos
* NUSP: 11917292
* 
* Curso: SCC0201 - Introdução à Ciência de Computação II
* Prof. Fernando Pereira dos Santos
*/


//A ideia: fazer um array simples de listas (no caso será um ponteiro duplo do tipo lista_t).
//Obs.: Cada nó na lista é uma struct contendo um ponteiro para aluno_t e um ponteiro pro próximo nó 
//definido em aluno.h
    

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "lista.h"

int hash(char *s){
    unsigned short int low = 1; //16 bits
    unsigned short int high = 0; //16 bits

    int i = 0;
    for (int i = 0; s[i] != '\0'; i++){
        low = (low + s[i]) % 65521;
        high = (high + low) % 65521;
    }

    unsigned int hashed_val = 0;
    hashed_val = high << 16;
    hashed_val = hashed_val | low;
    return hashed_val;
}

//Função usada para fazer login
void buscar(lista_t **ht, char nusp[], char senha[], int m){

    //Se não tivemos nenhum cadastro na hashtable, pra que iremos fazer busca?
    if (m == 0){
        printf("NUSP invalido\n");
        return;
    }

    int index = hash(nusp) % 200;
    int n_usp = atoi(nusp);

    //Caso encontremos esse NUSP na lista posição index
    if (esta_na_lista(ht[index], n_usp)){
        
        //Essa função irá retornar o objeto do aluno que corresponda ao n_usp pedido
        aluno_t *a = varrer_por_nusp(ht[index], n_usp);

        //Iremos comparar a senha armazenada no objeto aluno
        //com a tentativa de senha digitada no terminal
        int hashed_senha = get_hashedSenha(a);
        int try_senha = hash(senha);

        if (hashed_senha == try_senha){
            double *notas = get_notas(a);
            if (notas != NULL)
                printf("Notas: P1=%.1lf, P2=%.1lf, T1=%.1lf, T2=%.1lf\n", notas[0], notas[1], notas[2], notas[3]);
        }
        else{
            printf("Senha incorreta para o NUSP digitado\n");
        }
    }
    else
        printf("NUSP invalido\n");
}


void cadastrar(lista_t **ht, char nusp[], char senha[], double notas[]){

    //O hash iria ficar gigantesco sem módulo 200
    int index = hash(nusp) % 200; 

    int n_usp = atoi(nusp);

    //Fazemos uma varredura por esse NUSP na nossa lista na posição index
    //Caso encontremos algo, obviamente não podemos cadastrar
    if(esta_na_lista(ht[index], n_usp) == true)
        printf("NUSP ja cadastrado\n");
    
    else {
        aluno_t *a = criar_aluno();
        
        set_nusp(a, atoi(nusp));
        set_hashedSenha(a, hash(senha));
        set_notas(a, notas);
        
        //Estamos adicionando esse objeto aluno criado na lista posição index
        insere(ht[index], a);
        printf("Cadastro efetuado com sucesso\n");

    }
}

//Isso aqui é extremamente necessário senão varreremos por posições não inicializadas
//e aí da-lhe: segfault
void inicializar_ht(lista_t **ht){
    for (int i = 0; i < 200; i++){
        ht[i] = cria_lista();
    }
}

void destruir_ht(lista_t **ht){
    for (int i = 0; i < 200; i++){
        libera_lista(&ht[i]);
    }
    free(ht);
}

int main(){
    //1º entrada: obter o número de alunos a serem cadastrados (ou tentar)
    int n_alunos;
    scanf("%d", &n_alunos);


    lista_t **ht = (lista_t **) malloc(200 * sizeof(lista_t *));  
    inicializar_ht(ht);

    
    for (int i = 0; i < n_alunos; i++){
        char nusp[10];
        char senha[50];
        double notas[4];
        scanf("%s %s %lf %lf %lf %lf", nusp, senha, &notas[0], &notas[1], &notas[2], &notas[3]);
        cadastrar(ht, nusp, senha, notas);
    }
    
    int n_logins; 
    scanf("%d", &n_logins);

    for (int i = 0; i < n_logins; i++){
        char nusp[10];
        char senha[50];
        
        scanf("%s %s", nusp, senha);
        buscar(ht, nusp, senha, n_alunos);
    }

    destruir_ht(ht);

    return 0;
}