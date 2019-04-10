#ifndef TADPRODUTO_H
#define TADPRODUTO_H

#include <stdlib.h>
#include <stdio.h>

//typedef struct produto Produto;
//typedef struct estoque Estoque;

typedef struct {
  int codigo;
  char nome[30];
  float preco;
  int quantidade;
} Produto;

typedef struct {
  Produto estq[100];
  int prim;
  int ult;
} Estoque;

Estoque CriaEstoque ();
Produto CriaProduto ();
void InsereProduto (Estoque estq, Produto pdt);
void ImprimeEstoque (Estoque estq);
void ImprimeProduto (Produto pdt);


#endif
