#ifndef ABB_H
#define ABB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct arv Arv;

Arv* Cria_No (char letra, int peso);
int Retorna_Maior_Peso (Arv* a, Arv* b);
Arv* Cria_Arvore_Nos (Arv* a, Arv* b);
void Imprime(Arv* a);
Arv* Cria_Arvore_Vazia();

//funcao temporaria de teste
void Imprime_Info_No (Arv* x);
/*

Tree* Insere(Tree* a, int info);
Tree* Busca(Tree* a, int info);
Tree* Retira(Tree* a, int info);
void Libera(Tree* a);
*/

#endif
