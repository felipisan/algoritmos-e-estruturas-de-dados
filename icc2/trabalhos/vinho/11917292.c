/*
* Nome: Felipi Yuri Santos
* NUSP: 11917292
* 
* Curso: SCC0201 - Introdução à Ciência de Computação II
* Prof. Fernando Pereira dos Santos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Conta a quantidade de linhas de um arquivo.
//Parâmetros:
//      - (char *) file_name: nome do arquivo  
int countLines(char *file_name){    
    int lines = 0;
   
    FILE *temp = fopen(file_name, "r");
    char c = getc(temp);

    while (c != EOF){
        if (c == '\n')
            lines++;
        c = getc(temp);
    }
    
    fclose(temp);
    return lines;
}

//Coloca todos os registros de um arquivo CSV num vetor 
//Parâmetros:
//      - (FILE *) csv: o arquivo sendo lido
//      - (char *) file_name: o nome do arquivo
//      - (int *) i: ele conta quantos elementos o vetor terá (passado por referência)
float *csvToVector(FILE *csv, char *file_name, int *i){
    
    //Precisamos ignorar a primeira linha de um arquivo .csv
    fscanf(csv, "%*[^\n]\n");
    
    int file_line_ct = countLines(file_name);

    //Sabemos que são 6 campos para cada registro nesse "banco de dados" 
    float *vector = (float *) malloc(6 * file_line_ct * sizeof(float));
    *i = 0;
    char buffer[4096];

    while (!feof(csv)) {
        fscanf(csv, "%*[\',''\n']s"); //Pulando a vírgula se tiver e a quebra de linha
        fscanf(csv, "%[^\','^\'\n']s", buffer); //Lendo a parte depois da vírgula

        vector[*i] = atof(buffer); 
        (*i)++;
    }

    return vector;
}

typedef struct wine{
    int id;
    float citric_acid;
    float residual_sugar;
    float density;
    float pH;
    float alcohol;
} wine_t;

//Põe em um único vetor de tamanho size todos os valores da característica selecionada do vinho
//Parâmetros:
//      - (wine_t **) wine_list: o ponteiro duplo que aponta pros ponteiros da struct vinho_t
//      - (float *) ordering: o novo vetor que armazenará todas as características do vinho selecionada
//      - (char *) property_name: a string do nome da característica
//      - (int) size: a quantidade de vinhos existentes no .csv
void findProperty(wine_t **wine_list, float* ordering, char *property_name, int size){

    if (strcmp(property_name, "citric_acid") == 0){
        for (int i = 0; i < size; i++)
            ordering[i] = wine_list[i]->citric_acid;
    }

    else if (strcmp(property_name, "residual_sugar") == 0){
        for (int i = 0; i < size; i++)
            ordering[i] = wine_list[i]->residual_sugar;
    }

    else if (strcmp(property_name, "density") == 0){
        for (int i = 0; i < size; i++)
            ordering[i] = wine_list[i]->density;
    }

    else if (strcmp(property_name, "pH") == 0){
        for (int i = 0; i < size; i++)
            ordering[i] = wine_list[i]->pH;
    }
    
    else if (strcmp(property_name, "alcohol") == 0){
        for (int i = 0; i < size; i++)
            ordering[i] = wine_list[i]->alcohol;
    }
}

//Nosso algoritmo de ordernação proposto
//Parâmetros:
//      - (wine_t **) wine_list: o ponteiro duplo que aponta pros ponteiros da struct vinho_t
//      - (char *) property_name: a string do nome da característica
//      - (int) size: a quantidade de vinhos existentes no .csv
void wineSort(wine_t **wine_list, char *property_name, int size){

    float *ordering = (float *) malloc(size * sizeof(float));
    findProperty(wine_list, ordering, property_name, size);

    int i, j, max_position;
    for (i = 0; i < size - 1; i++){
        max_position = i;
        for (j = i + 1; j < size; j++){
            int a = wine_list[j]->id;
            int b = wine_list[max_position]->id;
            
            if (ordering[j] > ordering[max_position])
                max_position = j;
            else if(ordering[j] == ordering[max_position])
                if (a > b)
                    max_position = j;
        }
        
        if(max_position != i){
            float aux = ordering[max_position];
            ordering[max_position] = ordering[i];
            ordering[i] = aux;

            wine_t *tmp = wine_list[max_position];
            wine_list[max_position] = wine_list[i];
            wine_list[i] = tmp;
        }
    }
    free(ordering);
}

//Como o vetor ordenado fica em ordem decrescente, para facilitar a vida depois na busca fiz essa função
//Parâmetros:
//      - (wine_t **) wine_list: o ponteiro duplo que aponta pros ponteiros da struct vinho_t
//      - (int) size: a quantidade de vinhos existentes no .csv
void invertOrder(wine_t **wine_list, int size){
    for (int i = 0; i < size/2; i++){
        wine_t *aux = wine_list[i]; 
        wine_list[i] = wine_list[size - i - 1];
        wine_list[size - i - 1] = aux;  
    }
}

//Põe em um único vetor de tamanho size todos os valores da característica selecionada do vinho
//Parâmetros:
//      - (wine_t **) wine_list: o ponteiro duplo que aponta pros ponteiros da struct vinho_t
//      - (char *) property_name: a string do nome da característica
//      - (int) ini: início do vetor
//      - (int) end: fim do vetor
//      - (float) key: o registro buscado do campo
int binarySearch(wine_t** v, char *property_name, int ini, int end, float key){
    
    float *ordering = (float *) malloc(end * sizeof(float));
    findProperty(v, ordering, property_name, end);

    while(ini <= end){
        int center = ini + (end-ini)/2;
        if(ordering[0] == 0 && key == 0.00000){
            free(ordering);
            return 0;
        }

        if(ordering[center] == key){
            int x = 1;
            //Ajuste pra não explodir o tamanho do vetor
            if (center - 1 > 0){
                //Ajuste para pegar o menor entre elementos repetidos
                while(ordering[center - x] == key)
                    if (center - x - 1 > 0)
                        x++;
            }
            free(ordering);
            return center - x + 1;
        }

        else if(ordering[center] < key)
            ini = center + 1;
        else
            end = center - 1;
    }
    free(ordering);
    return -1;
}

//Algoritmo de contagem de ocorrências pra uma chave em questão no vetor do campo buscado
//Parâmetros:
//      - (wine_t **) wine_list: o ponteiro duplo que aponta pros ponteiros da struct vinho_t
//      - (int) size: tamanho do vetor
//      - (char *) property_name: a string do nome da característica
//      - (float) key: o registro buscado do campo
int countOccurrences(wine_t **v, int size, char *property_name, float key){
    float *ordering = (float *) malloc(size * sizeof(float));
    findProperty(v, ordering, property_name, size);

    int count = 0;
    for(int i = 0; i < size; i++){
        if (ordering[i] == key)
            count++;
    }

    free(ordering);
    return count;
}

int main(){
    //Parte 1: abrindo o arquivo e colocando todos seus valores num vetor único 
    //1º leitura do usuário: nome do arquivo
    char file_name[100]; 
    scanf("%s", file_name);
    getchar();

    FILE *csvFile = fopen(file_name, "r");
     
    //Tamanho do vetor propriedades
    int properties_count = 0; 
    float *property_value = csvToVector(csvFile, file_name, &properties_count);
    
    fclose(csvFile);

    //------------------------------------------------------------------------------
    //Parte 2: Determinando a quantidade de vinhos no arquivo, sabendo que trabalharemos com 6 campos.
    //Colocando todos esses dados num vetor de ponteiro duplo que aponta para ponteiros de struct wine_T

    int wineListSize = properties_count/6;
    wine_t **wine_list = (wine_t**) malloc((wineListSize) * sizeof(wine_t *));

    int i = 0;
    for (int k = 0; k < wineListSize; k++){
        wine_list[k] = (wine_t*) malloc(sizeof(wine_t));
        wine_list[k]->id = (int) property_value[i++];
        wine_list[k]->citric_acid = property_value[i++];
        wine_list[k]->residual_sugar = property_value[i++];
        wine_list[k]->density = property_value[i++];
        wine_list[k]->pH = property_value[i++];
        wine_list[k]->alcohol = property_value[i++];
    }
    free(property_value);


    //------------------------------------------------------------------------------
    //Parte 3: Ordenando de acordo com o campo desejado e fazendo as k buscas
    //3º leitura do usuário: k buscas e campo desejado

    int searches;
    scanf("%d", &searches);

    int foundWines;
    for(int k = 0; k < searches; k++){
        char field[25];
        scanf("%s", field);
        
        //Primeiro preparamos o vetor para a busca, ordenando-o adequadamente
        wineSort(wine_list, field, wineListSize);
        invertOrder(wine_list, wineListSize); 
        
        float key;
        scanf("%f", &key);
        
        //Fazendo a busca binária que volta a primeira recorrência
        int idx = binarySearch(wine_list, field, 0, wineListSize, key);
        foundWines = countOccurrences(wine_list, wineListSize, field, key);

        if(foundWines == 0)
            printf("Nenhum vinho encontrado\n");
        else{
            printf("ID: %d, ", wine_list[idx]->id);
            printf("Citric Acid: %.5f, ", wine_list[idx]->citric_acid);
            printf("Residual Sugar: %.5f, ", wine_list[idx]->residual_sugar);
            printf("Density: %.5f, ", wine_list[idx]->density);
            printf("pH: %.5f, ", wine_list[idx]->pH);
            printf("Alcohol: %.5f\n", wine_list[idx]->alcohol);
            printf("Total de vinhos encontrados: %d\n", foundWines);
        }
    }


    for (int k = 0; k < wineListSize; k++)
        free(wine_list[k]);
    free(wine_list);
    return 0;
}