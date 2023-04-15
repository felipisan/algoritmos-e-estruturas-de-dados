/*
* Nome: Felipi Yuri Santos
* NUSP: 11917292
* 
* Curso: SCC0202 - Algoritmos e Estruturas de Dados I
* Prof. Marcelo Manzato
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Pilha.h"
#include "item.h"

struct pilha {
	int topo;
	ITEM *itens[TAM];
};

PILHA *pilha_criar() {
	PILHA *p = (PILHA *)malloc(sizeof(PILHA));
	assert(p != NULL);
	p->topo = -1;
	return p;
}

bool pilha_empilhar(PILHA *pilha, ITEM *x) {
	assert(pilha != NULL);
	if(!pilha_cheia(pilha)) {
		pilha->topo += 1;
		pilha->itens[pilha->topo] = x;
		return true;
	}
	return false;
}

ITEM* pilha_topo(PILHA* pilha){
	assert(pilha != NULL);
	if(!pilha_vazia(pilha)) {
		return pilha->itens[pilha->topo];
	}
	return false;
}

bool pilha_cheia(PILHA *pilha) {
	assert(pilha != NULL);
	if(pilha->topo == TAM - 1) {
		return true; 
	}
	return false;
}

bool pilha_vazia(PILHA *pilha) {
	assert(pilha != NULL);
	if(pilha->topo == -1) {
		return true; 
	}
	return false;
}

void pilha_apagar(PILHA **pilha) {
	if(*pilha != NULL) {
		free(*pilha);
		*pilha = NULL;
	}
}

ITEM* pilha_desempilhar(PILHA *pilha) {
	assert(pilha != NULL);
	if(!pilha_vazia(pilha)){
		return pilha->itens[pilha->topo--];
	}
}

bool isDigit(char c){
	if (c >= 48 && c <= 57)
		return true;
	else
		return false;
}

bool isOp(char c){
	if (c == '+' || c == '*' || c == '-' || c == '/')
		return true;
	else 
		return false;
}

float rpn(char *sequencia){
	PILHA* p = pilha_criar();

	int i = 0; //O iterador da sequência (definida por apenas uma linha, ou seja, até um \0)
	while(sequencia[i] != '\0'){
		if(isDigit(sequencia[i]) == true) //A lógica da RPN é: se for um dígito, empilhamos	
			pilha_empilhar(p, item_criar((float) sequencia[i] - 48));

		//Se for uma operação, desempilhamos os dois dígitos e empilhamos o resultado
		else if(isOp(sequencia[i]) == true){
			////Apenas lembrando que a ordem dos números precisa ser a contrária 
			//porque uma pilha é uma estrutura de dados LIFO enão uma FIFO
			ITEM *a = pilha_desempilhar(p);
			ITEM *b = pilha_desempilhar(p);
			float y = item_get_chave(a);
			float x = item_get_chave(b);
			
			item_apagar(&a);
			item_apagar(&b);

			switch (sequencia[i]){ 
				case '+':
					pilha_empilhar(p, item_criar(x + y));
					break;
				case '-':
					pilha_empilhar(p, item_criar(x - y));
					break;
				case '*':
					pilha_empilhar(p, item_criar(x * y));
					break;
				case '/':
					pilha_empilhar(p, item_criar(x / y));
					break;
			}
		}
		else{
			printf("Operacao invalida");
			exit(1);
		}
		i++;
	}	
	ITEM* x = pilha_desempilhar(p);
	float res = item_get_chave(x);

	//Se tudo foi digitado corretamente, haverá apenas um único elemento na pilha
	//(o resultado)
	item_apagar(&x); 
   	pilha_apagar(&p);
	return res;
}