#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void){

    //Teste com e sem isso:
    srand(time(NULL));

    int x = rand()%100;
    printf("%d\n", x);
    return 0;

}


