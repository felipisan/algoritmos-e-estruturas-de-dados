#include <stdlib.h>
#include <stdio.h>

typedef struct data {
    int id, year;
    double size;
} data_t;

typedef short int (*fComp)(data_t, data_t);

// lê do arquivo passado os dados e os retorna estruturados
data_t* readData(char *filename, int size) {

    // abertura do arquivo para leitura
    FILE *file = fopen(filename, "r");
    if (file == NULL) return NULL;

    // leitura e descarte da primeira linha do arquivo
    char aux[30];
    fscanf(file, "%s", aux);

    // leitura dos dados
    data_t *data = (data_t *)malloc(size * sizeof(data_t));
    for (int i = 0; i < size; i ++)
        fscanf(file, " %d,%d,%lf", &data[i].id, &data[i].year, &data[i].size);

    fclose(file);
    return data;
}

// mostra todos os elementos da estrutura passada
void printData(data_t *data, int size) {

    for (int i = 0; i < size; i ++)
        printf("%d - %d - %.2lf\n", data[i].id, data[i].year, data[i].size);
}

// ordena o vetor de dados de acordo com a comparação utilizada
void sort(data_t *data, int size, fComp func) {

    for (int i = 0; i < size - 1; i ++) {
        for (int j = 0; j < size - i - 1; j ++) {
            // verifica condição de troca
            if (func(data[j], data[j+1])) {
                data_t aux = data[j];
                data[j] = data[j+1];
                data[j+1] = aux;
            }
        }
    }

    // mostra os dados ordenados
    printData(data, size);
}

// comparador para os anos
short int compYear(data_t d1, data_t d2) {
    return d1.year > d2.year;
}

// comparador para os tamanho
short int compSize(data_t d1, data_t d2) {
    return d1.size > d2.size;
}

int main() {

    // informações do arquivo de dados
    char fileName[20] = "data.txt";
    int size = 4;

    // leitura dos dados
    data_t *fileData = readData(fileName, size);

    // ordenação da estrutura
    sort(fileData, size, compSize);
    free(fileData);
}