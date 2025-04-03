#include "fila.h"
#include <stdlib.h>

typedef struct Elemento{
	int dado;
	struct Elemento* proximo;
} Elemento;

struct Fila{
	Elemento* inicio;
	Elemento* fim;
};

Fila* fila_criar(){
	Fila* f= (Fila*)malloc(sizeof(Fila));
	f->inicio = f->fim = NULL;
	return f;
}

void fila_enfileirar(Fila* f, int valor){
	Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
	novo->dado = valor;
	novo->proximo = NULL;
	
	if(f->fim == NULL){
		f->inicio = f->fim = novo;
	}else{
		f->fim->proximo = novo;
		f->fim = novo;	
	}
}


int fila_desenfileirar(Fila* f){
	if(fila_vazia(f))return -1;
	
	Elemento* temp= f->inicio;
	int valor = temp->dado;
	
	f->inicio = f->inicio->proximo;
	if(f->inicio == NULL){
		f->fim = NULL;
	}
	
	free(temp);
	return valor;
}

int fila_frente(Fila* f){
	if(fila_vazia(f))return -1;
	return f->inicio->dado;
}

int fila_vazia(Fila* f){
	return f->inicio == NULL;
}

void fila_destruir(Fila* f){
	while(!fila_vazia(f)){
		fila_desenfileirar(f);
	}
	free(f);
}
