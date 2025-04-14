
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cardapio.h"

#define TAM_NOME 50

typedef struct Item {
    int ID;
    char nome[TAM_NOME];
    float preco;
    struct Item* proximo;
} Item;

struct Cardapio {
    Item* inicio;
};

Cardapio* cardapio_criar() {
    Cardapio* c = malloc(sizeof(Cardapio));
    c->inicio = NULL;
    return c;
}

void cardapio_adicionar(Cardapio* c, int ID, const char* nome, float preco) {
    Item* novo = malloc(sizeof(Item));
    novo->ID = ID;
    strncpy(novo->nome, nome, TAM_NOME);
    novo->preco = preco;
    novo->proximo = c->inicio;
    c->inicio = novo;
}

float cardapio_obter_preco(Cardapio* c, int ID) {
    Item* atual = c->inicio;
    while (atual) {
        if (atual->ID == ID) return atual->preco;
        atual = atual->proximo;
    }
    return -1.0f; 
}

const char* cardapio_obter_nome(Cardapio* c, int ID) {
    Item* atual = c->inicio;
    while (atual) {
        if (atual->ID == ID) return atual->nome;
        atual = atual->proximo;
    }
    return NULL;
}

void cardapio_imprimir(Cardapio* c) {
    Item* atual = c->inicio;
    printf("\n--- Cardápio ---\n");
    while (atual) {
        printf("%d. %s - R$ %.2f\n", atual->ID, atual->nome, atual->preco);
        atual = atual->proximo;
    }
    printf("----------------\n");
}

void cardapio_destruir(Cardapio* c) {
    Item* atual = c->inicio;
    while (atual) {
        Item* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(c);
}
