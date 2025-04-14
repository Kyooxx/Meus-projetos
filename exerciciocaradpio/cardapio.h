
#ifndef CARDAPIO_H
#define CARDAPIO_H

typedef struct Cardapio Cardapio;

Cardapio* cardapio_criar();
void cardapio_adicionar(Cardapio* c, int ID, const char* nome, float preco);
float cardapio_obter_preco(Cardapio* c, int ID);
const char* cardapio_obter_nome(Cardapio* c, int ID);
void cardapio_imprimir(Cardapio* c);
void cardapio_destruir(Cardapio* c);

#endif
