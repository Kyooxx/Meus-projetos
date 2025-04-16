//pilha.c//

#include "pilha.h"
#include <stdlib.h>

typedef struct Elemento{
	int dado;
	struct Elemento* proximo;
}Elemento;

struct Pilha{
	Elemento* topo;
};

Pilha* pilha_criar(){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

void pilha_push(Pilha*p, int valor){
	Elemento*novo = (Elemento*)malloc(sizeof(Elemento));
	novo->dado = valor;
	novo->proximo = p->topo;
	p->topo = novo;
}

int pilha_pop(Pilha* p){
	if(pilha_vazia(p)) return -1;
	
	Elemento* removido = p->topo;
	int valor = removido->dado;
	p->topo = removido->proximo;
	free(removido);
	return valor;
}

int pilha_top(Pilha* p){
	if(pilha_vazia(p)) return -1;
	return p->topo->dado;
}

int pilha_vazia(Pilha* p){
	return p->topo == NULL;
}

void pilha_destruir(Pilha* p){
	while(!pilha_vazia(p)){
		pilha_pop(p);
	}
	free(p);
}
