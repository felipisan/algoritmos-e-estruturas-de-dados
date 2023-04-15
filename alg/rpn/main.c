#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
   char str_sequencia[105];
   
   while(scanf("%s", str_sequencia) != EOF){
      float resultado = rpn(str_sequencia);

      printf("%.2f\n", resultado);
   }    

   return 0;
}