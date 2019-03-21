#include <stdio.h>
#include <stdlib.h>

int main () {
  float e;
  printf("Digite um número: \n");
  scanf("%f", &e);
  e *= e;
  printf("O Quadrado é: %f\n", e);

  return 0;
}
