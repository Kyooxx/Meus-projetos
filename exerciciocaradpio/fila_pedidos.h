
#ifndef FILA_PEDIDOS_H
#define FILA_PEDIDOS_H

#include "cardapio.h"

typedef struct FilaPedidos FilaPedidos;

FilaPedidos* fila_criar();
void fila_adicionar_pedido(FilaPedidos* fila, int numeroMesa, int* ids, int quantidade, Cardapio* c);
void fila_processar_proximo(FilaPedidos* fila, Cardapio* c);
void fila_destruir(FilaPedidos* fila);

#endif
