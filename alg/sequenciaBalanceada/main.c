#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "item.h"

bool balanceada(char *sequencia){
   PILHA *p = pilha_criar();
   int i = 0;
   ITEM *x;
   while (sequencia[i] != '\0'){

      if(sequencia[i] == '(' || sequencia[i] == '[' || sequencia[i] == '{')
         pilha_empilhar(p, item_criar(sequencia[i]));

      else if (sequencia[i] == ')' || sequencia[i] == ']' || sequencia[i] == '}'){
         x = pilha_topo(p);

         //Esse if verifica se nenhum caractere de fechamento foi colocado no começo da sequência
         //tipo: ](({}))
         if(!pilha_vazia(p)){ 

            char ultimo = item_get_chave(x);
            
            
            char fechamento;
            if(ultimo == '(')
               fechamento = ')';

            else if(ultimo == '[')
               fechamento = ']';

            else if(ultimo == '{')
               fechamento = '}';

            
            //Caso um caractere de fechamento seja verificado na sequência,
            //mas o caractere de abertura correspondente não seja do mesmo tipo 
            //(chave, colchete ou parêntese), a sequência nunca ficará balanceada, 
            //então otimizamos o algoritmo encerrando a execução aqui, colocando
            //esse caractere de fechamento na pilha e saindo do while 
            //já que meu sistema de verificação consiste em ver de a pilha está vazia
            //para saber se está balanceada ou não
            if (sequencia[i] == fechamento){
               pilha_desempilhar(p);
               item_apagar(&x);
            }
            else{
               pilha_empilhar(p, item_criar(sequencia[i]));
               break;
            }

         } 
         //A sequência sempre estará balanceada se a pilha estiver vazia, colocando
         //um caractere de fechamento no começo impedirá pra sempre que aquela sequência  
         //fique balanceada no final
         else{
            pilha_empilhar(p, item_criar(sequencia[i]));
            break;
         }

      }
      i++;
   }

   //A partir daqui já temos a nossa resposta. 
   //Se a sequência quebrou as regras de balanceamento, a pilha não estará vazia
   //do contrário, estará balanceada.
   //(no que diz respeito à ordem e quantidade dos fechamentos)
   bool flag = pilha_vazia(p);

   //Isso serve pra evitar memory leaks!
   while(!pilha_vazia(p)){
      x = pilha_desempilhar(p);
      item_apagar(&x);
   }
   pilha_apagar(&p); //Isso também
   
   

   if(flag == true){
      return true;
   }
   else
      return false;
}

int main(int argc, char *argv[]){
   char str_sequencia[300];
   int qtd=0;
   
   /*qtd de sequencias a serem lidas e analisadas*/
   scanf("%d", &qtd);

   for(int i=0; i<qtd; i++){
      scanf("%s", str_sequencia);
      if(balanceada(str_sequencia))
      	printf("BALANCEADO\n");
      else
      	printf("NÃO BALANCEADO\n");
   }   
   return 0;
   
}


