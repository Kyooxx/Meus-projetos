#include <stdio.h>
#include <stdlib.h>
#include "fila_pedidos.h"

typedef struct Pedido {
    int numeroMesa;
    int* ids;
    int quantidade;
    float total;
    struct Pedido* prox;
} Pedido;

struct FilaPedidos {
    Pedido* inicio;
    Pedido* fim;
};

FilaPedidos* fila_criar() {
    FilaPedidos* f = malloc(sizeof(FilaPedidos));
    f->inicio = f->fim = NULL;
    return f;
}

void fila_adicionar_pedido(FilaPedidos* fila, int numeroMesa, int* ids, int quantidade, Cardapio* c) {
    Pedido* novo = malloc(sizeof(Pedido));
    novo->numeroMesa = numeroMesa;
    novo->ids = malloc(sizeof(int) * quantidade);
    novo->quantidade = quantidade;
    novo->total = 0.0f;

    for (int i = 0; i < quantidade; i++) {
        novo->ids[i] = ids[i];
        novo->total += cardapio_obter_preco(c, ids[i]);
    }

    novo->prox = NULL;

    if (fila->fim)
        fila->fim->prox = novo;
    else
        fila->inicio = novo;
    fila->fim = novo;
}

void fila_processar_proximo(FilaPedidos* fila, Cardapio* c) {
    if (!fila->inicio) {
        printf("Nenhum pedido na fila.\n");
        return;
    }

    Pedido* p = fila->inicio;
    printf("=================================\n");
    printf("PEDIDO PROCESSADO\n");
    printf("=================================\n");
    printf("Mesa: %d\n", p->numeroMesa);
    printf("Itens:\n");
    for (int i = 0; i < p->quantidade; i++) {
        const char* nome = cardapio_obter_nome(c, p->ids[i]);
        float preco = cardapio_obter_preco(c, p->ids[i]);
        if (nome)
            printf("%d. %s - R$ %.2f\n", p->ids[i], nome, preco);
        else
            printf("%d. [Item não encontrado]\n", p->ids[i]);
    }
    printf("Total: R$ %.2f\n", p->total);
    printf("=================================\n");

    fila->inicio = p->prox;
    if (!fila->inicio) fila->fim = NULL;

    free(p->ids);
    free(p);
}

void fila_destruir(FilaPedidos* fila) {
    while (fila->inicio) {
        Pedido* temp = fila->inicio;
        fila->inicio = temp->prox;
        free(temp->ids);
        free(temp);
    }
    free(fila);
}
