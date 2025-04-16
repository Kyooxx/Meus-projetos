
//#ifndef PILHA_H
#define PILHA_H

typedef struct Pilha Pilha;

Pilha* pilha_criar();

void pilha_push(Pilha* p, int valor);

int pilha_pop(Pilha* p);

int pilha_top(Pilha* p);

int pilha_vazia(Pilha* p);

void pilha_destruir(Pilha* p);

#endif//


