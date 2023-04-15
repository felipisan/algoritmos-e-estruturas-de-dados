//
//  main.c
//  Trabalho4_ Ordens
//
//  Created by Vicenzo D’Arezzo and Felipi Yuri Santos on 22/10/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

/* Amarelo - 0 / azul - 1 / branco - 2/ preto - 3/ rosa - 4/ verde - 5, vermelho - 6*/
//definição da estrutura
typedef struct brinq{
    int id;
    int cor;
    float tamanho;
    float nota;
}brinquedo;

//leitura:
brinquedo *leitura(int n){
    char str_cor[50];
    
    //criando o vetor de brinquedos:
    brinquedo * vetor = malloc(n * sizeof(brinquedo));
    assert(vetor);
    //fazendo a leitura
    for(int i = 0; i < n; i++){
        vetor[i].id = i;
        scanf("%s %f %f", str_cor, &vetor[i].tamanho, &vetor[i].nota);
        //comparando as strings:
        if(strcmp(str_cor, "amarelo") == 0){
            vetor[i].cor = 0;
        }else if(strcmp(str_cor, "azul") == 0){
            vetor[i].cor = 1;
        }else if(strcmp(str_cor, "branco") == 0){
            vetor[i].cor = 2;
        }else if(strcmp(str_cor, "preto") == 0){
            vetor[i].cor = 3;
        }else if(strcmp(str_cor, "rosa") == 0){
            vetor[i].cor = 4;
        }else if(strcmp(str_cor, "verde") == 0){
            vetor[i].cor = 5;
        }else if(strcmp(str_cor, "vermelho") == 0){
            vetor[i].cor = 6;
        }
    }
    
    return vetor;
}

// a lógica do ehMenor(a, b) basicamente atesta se um brinquedo a deve, pelas regras da ordenação
// do exercício, vir antes do brinquedo b. se a resposta for sim, geralmente mantemos a ordenação
// se não, trocamos os brinquedos de posição.
bool ehMenor(brinquedo a, brinquedo b){
    //Sabemos que os brinquedos são da mesma cor, portanto queremos analisar seus tamanhos.
    
    if(a.tamanho == b.tamanho){
        //para brinquedos de mesmo tamanhos, o desempate se dá pela nota:
        if( a.nota >= b.nota){
            return true;
        }else{
            return false;
        }
    }else{
        if( a.tamanho < b.tamanho){
            return true;
        }else{
            return false;
        }
    }
}

void bubblesort(brinquedo *v, int tamanho){
    brinquedo aux;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho - 1; j++){
            if(v[j].cor > v[j+1].cor){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }else if (v[j].cor == v[j+1].cor){
                if(!ehMenor(v[j], v[j+1])){
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }
    }
}

void insertionSort (brinquedo *v, int tamanho){
    brinquedo eleito;
    int j;

    for(j = 1; j < tamanho; j++){
        eleito = v[j];
        
        int i = j - 1;
        while(i >= 0 && v[i].cor >= eleito.cor){
            if(v[i].cor == eleito.cor){
                if(!ehMenor(eleito, v[i]))
                    break;
            }
            v[i+1] = v[i];
            i--;
        }
        
        v[i + 1] = eleito;
    }
}

void ordenacao_interacalando(int inicio, int fim, brinquedo *v){
    int meio = (int) (inicio + fim)/2;
    int contador1 = inicio, contador2 = meio + 1;
    int contador_vetor = 0;
    brinquedo vetor_aux[fim - inicio + 1];
    
    while(contador1 <= meio && contador2 <= fim){
        if(v[contador1].cor < v[contador2].cor){
            vetor_aux[contador_vetor] = v[contador1];
            contador1++;
        }else if(v[contador1].cor == v[contador2].cor){
            if(!ehMenor(v[contador1], v[contador2])){
                vetor_aux[contador_vetor] = v[contador2];
                contador2++;
            }else{
                vetor_aux[contador_vetor] = v[contador1];
                contador1++;
            }
        }else{
            vetor_aux[contador_vetor] = v[contador2];
            contador2++;
        }
        contador_vetor++;
    }
    
    while(contador1 <= meio) {
        vetor_aux[contador_vetor] = v[contador1];
        contador1++;
        contador_vetor++;
    }
    while(contador2 <= fim) {
        vetor_aux[contador_vetor] = v[contador2];
        contador2++;
        contador_vetor++;
    }
    
    for(int i = inicio, j = 0; i <= fim; i++, j++){
        v[i] = vetor_aux[j];
    }
}

void mergeSort(brinquedo *v, int ini, int fim){
    
    if(fim <= ini){
        return;
    }
    
    int meio = (int)(ini + fim)/2;
    
    mergeSort(v, ini, meio);
    mergeSort(v, meio + 1, fim);
    ordenacao_interacalando(ini, fim, v);
}

bool desemp(brinquedo a, brinquedo b){
    if(a.cor != b.cor)
        return a.cor < b.cor;
    
    if(a.tamanho != b.tamanho)
        return a.tamanho < b.tamanho;
    
    return (a.nota >= b.nota);
}

void quickSort(brinquedo* vetor, int inicio, int fim){
	if (fim <= inicio)
		return;

	brinquedo aux;
	
	int pivo = inicio;
	int i = inicio+1;
	int j = fim;

	while (i <= j){
		while (i <= fim && (desemp(vetor[i], vetor[pivo]))) i++;
		while (desemp(vetor[pivo], vetor[j])) j--;

		if (j <= i){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
	}

	pivo = j;
	aux = vetor[pivo];
	vetor[pivo] = vetor[inicio];
	vetor[inicio] = aux;

	quickSort(vetor, inicio, pivo-1);
	quickSort(vetor, pivo+1, fim);	
}

int main(void) {
    //lendo o tamanho:
    int n;
    scanf("%d ", &n);
    brinquedo * vetor = leitura(n);
    
    //Bubble Ok!
    // bubblesort(vetor, n);

    //Insertion Ok!
    // insertionSort(vetor, n);

    //Merge Ok!
    //mergeSort(vetor, 0, n - 1);
    
    //QuickSort
    quickSort(vetor, 0, n - 1);

    //testando leitura:
    for(int i = 0; i < n; i++){
        printf("%d;", vetor[i].id);
    }
    
    //apagando vetor:
    free(vetor);
    vetor = NULL;
    return 0;
}
