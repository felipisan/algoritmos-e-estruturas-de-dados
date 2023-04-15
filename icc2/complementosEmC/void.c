#include <stdio.h>
#include <stdlib.h>

// estrutura de nossa pilha genérica
typedef struct stack {
    int top;
    void **elements;
} stack_t;

// cria uma pilha vazia
stack_t* create() {

    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    stack->top = -1;
    stack->elements = NULL;

    return stack;
}

// insere um elemento na pilha
void push(stack_t *stack, void *elem) {

    stack->top ++;
    stack->elements = (void **)realloc(stack->elements, (stack->top + 1) * sizeof(void *));
    stack->elements[stack->top] = elem;
}

// retira e retorna o elemento do topo da pilha
void* pop(stack_t *stack) {

    void *ret = stack->elements[stack->top];
    stack->top --;
    stack->elements = (void **)realloc(stack->elements, (stack->top + 1) * sizeof(void *));

    return ret;
}

// remove da memória toda a pilha
void removeST(stack_t *stack) {
    free(stack->elements);
    free(stack);
}

int main() {

    stack_t *s = create();
    
    // inserção na pilha
    int elem = 2;
    push(s, &elem);
    double elem2 = 3.591;
    push(s, &elem2);
    char elem3 = 'h';
    push(s, &elem3);
    long int elem4 = 90000000000000000;
    push(s, &elem4);

    // remoção e leitura
    void *genericElem;
    genericElem = pop(s);
    printf("%ld ", *(long int *)genericElem);
    genericElem = pop(s);
    printf("%c ", *(char *)genericElem);
    genericElem = pop(s);
    printf("%.3lf ", *(double *)genericElem);
    genericElem = pop(s);
    printf("%d ", *(int *)genericElem);

    printf("\n");
    removeST(s);
}