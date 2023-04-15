#include <stdio.h>

int fibo(int n){
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main(int argc, char *argv[]){
    int n;
    printf("Type a number... ");
    scanf("%d", &n);
    if (n <= 0){
        printf("Hurrrr zerésimo termo da sequência uau ein shockou meu sistema ai ;(\n");
        return 1;
    }

    printf("O %dº termo da sequência de Fibonacci é: %d", n, fibo(n));
    printf("\n");
    return 0;
}