#include <stdio.h>
#include <stdlib.h>
#include "cardapio.h"
#include "fila_pedidos.h"

int main() {
    printf("== ATENDIMENTO DA CAFETERIA ===\n");

    Cardapio* cardapio = cardapio_criar();
    cardapio_adicionar(cardapio, 1, "Café Expresso", 5.00f);
    cardapio_adicionar(cardapio, 2, "Pão de Queijo", 8.00f);
    cardapio_adicionar(cardapio, 3, "Bolo de Fubá", 7.50f);

    cardapio_imprimir(cardapio);

    FilaPedidos* fila = fila_criar();

    int itens_mesa10[] = {1, 2};
    fila_adicionar_pedido(fila, 10, itens_mesa10, 2, cardapio);

    int itens_mesa5[] = {3};
    fila_adicionar_pedido(fila, 5, itens_mesa5, 1, cardapio);
    fila_processar_proximo(fila, cardapio);
    fila_processar_proximo(fila, cardapio);
    fila_destruir(fila);
    cardapio_destruir(cardapio);

    return 0;
}
