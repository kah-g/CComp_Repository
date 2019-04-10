#include "tadProduto.h"

int main () {
  Estoque estq01 = CriaEstoque();
  Produto pdt = CriaProduto();
  InsereProduto(estq01, pdt);
  ImprimeProduto(pdt);
  ImprimeEstoque(estq01);
  return 0;
}
