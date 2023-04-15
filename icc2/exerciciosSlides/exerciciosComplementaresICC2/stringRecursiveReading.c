#include <stdio.h>
#include <string.h>

// Empilha tudo na chamada de funções
// Pilha: 0 1 2 3 4 5 6 7 8 9 10
//        C o r i n t h i a n s
//
// o topo está apontando pra 10.
// e depois vai chamando tudo ao contrário
// quando ele faz o return, ele lembra qual é 
// o incremento do ponteiro que tava na chamada anterior
// 
// 
// Pilha de funções:
// chamando string_twist de st() só:
// 
//   (str +)  0        1       2       3      4      5       6      7      8      9      10     
//           st(0)   st(1)   st(2)   st(3)  st(4)  st(5)   st(6)  st(7)  st(8)  st(9)  st(10)
//                                                                                       -> quando chegar aqui vai 
//                                                                               parar de empilhar, começando 
//                                                                               der pop na pilha de chamada de funções.
//
void string_twist(char *str){
    if(*str != '\0'){
        string_twist(str + 1); //Incrementando em 1 o ponteiro para ele mandar p função o próximo char 
        printf("%c", *str);
    }
}

int main(){

    char ss[100];
    scanf("%s", ss);
    
    string_twist(ss);
    printf("\n");

    return 0;
}