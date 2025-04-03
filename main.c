#include "fila.c"
#include <stdio.h>

int main(){
	Fila* fila = fila_criar();
	
	fila_enfileirar(fila,10);
	fila_enfileirar(fila,20);
	fila_enfileirar(fila,30);
	
	printf("Frente: %d\n", fila_frente(fila));
	
	printf("Desenfileirando: %d\n", fila_desenfileirar(fila));
	printf("Desenfileirando: %d\n", fila_desenfileirar(fila));

	printf("Frente: %d\n", fila_frente(fila));
	fila_destruir(fila);
	return 0;
}
