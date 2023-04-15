#include<stdio.h>


int isPrime(int n, int i){
    
    //Casos-base
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    
    return isPrime(n, i + 1);
}

int main(int argc, char *argv[]){
    int n;
    printf("Type a number... ");
    scanf("%d", &n);
    
    int isThisIt = isPrime(n, 2);
    (isThisIt) ? printf("The number is a Prime!") : printf("The number is not a prime xD");
    printf("\n");
    return 0;
}