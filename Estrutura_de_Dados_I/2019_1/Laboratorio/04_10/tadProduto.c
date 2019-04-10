#include "tadProduto.h"

/*struct produto {
  int codigo;
  char nome[30];
  float preco;
  int quantidade;
};

struct estoque {
  Produto estq[100];
  int prim;
  int ult;
};*/

Estoque CriaEstoque () {
  Estoque estq;
  estq.prim = 0;
  estq.ult = 0;
  return estq;
}

Produto CriaProduto () {
  Produto pdt;
  printf("Entre com as informacoes do produto:\n");
  printf("Codigo:\n");
  scanf("%d", &pdt.codigo);
  printf("Nome:\n");
  scanf("%s", pdt.nome);
  printf("Preco:\n");
  scanf("%f", &pdt.preco);
  printf("Quantidade:\n");
  scanf("%d", &pdt.quantidade);
  return pdt;
}

void InsereProduto (Estoque estq, Produto pdt) {
  if (estq.prim == 0 && estq.ult == 0) {
    printf("prim %d ult %d\n", estq.prim, estq.ult);
    estq.estq[estq.prim] = pdt;
    estq.prim = 1;
    estq.ult = 1;
    printf("prim %d ult %d\n", estq.prim, estq.ult);
  } else {
    printf("da prim %d ult %d\n", estq.prim, estq.ult);
    estq.estq[estq.ult] = pdt;
    estq.ult++;
  }
}

void ImprimeEstoque (Estoque estq) {
  for (int i=0; i < (estq.ult)-1; i++) {
    printf("\nCodigo: %d, Produto: %s, Preco: %.2f, Quantidade: %d.\n", estq.estq[i].codigo, estq.estq[i].nome, estq.estq[i].preco, estq.estq[i].quantidade);
  }
}

void ImprimeProduto (Produto pdt) {
  printf("\nCodigo: %d, Produto: %s, Preco: %.2f, Quantidade: %d.\n", pdt.codigo, pdt.nome, pdt.preco, pdt.quantidade);
}
