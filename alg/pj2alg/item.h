#ifndef ITEM_H
#define ITEM_H

    typedef int elem; // elemento genérico
    typedef struct item item_t;

    item_t *criar_item(elem elemento);
    void set_valor(item_t *item, elem elemento);
    elem get_valor(item_t *item);
    void apagar_item(item_t **item);

#endif
