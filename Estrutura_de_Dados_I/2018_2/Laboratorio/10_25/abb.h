#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arv Tree;

Tree* CriaArvoreVazia();
void ImprimeCrescente(Tree* a);
Tree* Insere(Tree* a, int info);
Tree* Busca(Tree* a, int info);
Tree* Retira(Tree* a, int info);
void Libera(Tree* a);

#endif
