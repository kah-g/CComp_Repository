#include <stdio.h>
#include <stdlib.h>

int main () {
  //se o numero for valido, ele sera descrescido ate chegar a 2
  int n;
  printf("Entre com um numero par positivo\n");
  scanf("%d", &n);
  if (((n%2) != 0) || (n < 0)) {
    printf("Numero Invalido\n");
    //scanf("%d", &n);
    //ñ funciona como planejado, apos ler o numero encerra a execucao
  } else {
    for (;n!=0;) {
      printf("%d\n", n);
      n = n-2;
    }
  }

  return 0;
}
