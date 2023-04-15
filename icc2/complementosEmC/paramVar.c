#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h> // biblioteca necessária

// concatena um número variável de strings passadas
char* concat(const char *str1, ...) {
    
    // inicializa a leitura dos argumentos
    va_list args;
    va_start(args, str1);

    // inicializa os valores da concatenação
    size_t len = strlen(str1) + 1;
    char *aux, *res = (char *)malloc(len * sizeof(char));
    strcpy(res, str1);

    // enquanto não houver um argumento nulo, lê e concatena
    while ((aux = va_arg(args, char*))) {
        len += strlen(aux);
        res = (char *)realloc(res, len * sizeof(char));
        strcat(res, aux);
    }

    // finaliza a leitura dos argumentos e retorna a string gerada
    va_end(args);
    res[len-1] = '\0';
    return res;
}

int main() {

    char *str = concat("ola", " ", "mundo", "!", " :)", NULL);
    printf("%s\n", str);
    free(str);

    return 0;
}