void fila_apagar(FILA **fila)
{
    ITEM *removido = fila_remover(*fila);
    item_apagar(&removido);
    fila_apagar(fila);
   free(*fila);

}