#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int codigo;
  float preco;
  int qtdEstoque;
} tProduto;

tProduto LeProduto ();
int EhProduto1MaiorQ2 ();
int EhProduto1MenorQ2 ();
int TemProdutoEmEstoque ();
void ImprimeProduto ();

int main () {
  int qtd, i;
  tProduto pdt01;
  scanf("%d", &qtd);
  for (i=0; i < qtd; i++) {
    scanf("%d %f %d", &pdt01.codigo, &pdt01.preco, &pdt01.qtdEstoque);
  }

  return 0;
}

tProduto LeProduto ();
int EhProduto1MaiorQ2 ();
int EhProduto1MenorQ2 ();
int TemProdutoEmEstoque ();
void ImprimeProduto ();
