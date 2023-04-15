bool ehABB(NO* raiz, int min, int max){
    if (raiz == NULL) return 1;

    //Definiremos na função principal os valores mínimo e máximo permitidos
    //Caso em algum momento o nó contenha um valor menor que o mínimo ou maior que o máximo, 
    //já garantimos que não é uma ABB.
    if (item_get_chave(raiz->item) < min)
        return false;
    if (item_get_chave(raiz->item) > max)
        return false;

    //Primeiro percorreremos toda a árvore pela esquerda (numa ABB, o filho esquerdo é um valor menor que
    //o próprio nó, então, pela lógica, se descermos até o final da árvore sempre pela esquerda,
    //iremos encontrar o mínimo correto (diferente do especificado na função is_abb(AB *T))
    //O mesmo raciocínio vale para encontrar o maior valor que há na árvore pela direita
    //Além disso, para cada vez que vamos descendo na árvore, temos que diminuir o valor máximo e mínimo de acordo
    //com o lado que estamos descendo, e esse valor pela lógica da ABB deve ser menor que a raiz atual ou maior, 
    //caso estejamos descendo na árvore pela direita.
    //Caso tenhamos chego ao nó folha mais à esquerda, e ele é o maior que o valor mínimo e (AND)
    //tenhamos chego ao nó folha mais à direita possível, e ele é menor que o valor máximo
    //então temos certeza que é uma ABB.
    return ehABB(raiz->esq, min, item_get_chave(raiz->item) - 1) && ehABB(raiz->dir, item_get_chave(raiz->item) + 1, max);
}

bool is_abb(AB *T){
    //Passar a árvore como referência toda vez é muito custoso!
    return ehABB(T->raiz, 0, 999999);
}