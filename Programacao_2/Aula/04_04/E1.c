#include <stdio.h>
#include <stdlib.h>

int main () {
  //calcular a media de n numeros - diferentes numeros
  int q, c, r, n, soma = 0;
  printf("Entre com a quantidade\n");
  scanf("%d", &q);
  c = 0;
  printf("Entre com %d números\n", q);
  while (c < q) {
    scanf("%d", &n);
    soma += n;
    c++;
  }
  r = soma / q;
  printf("Resultado: %d\n", r);

  return 0;
}
