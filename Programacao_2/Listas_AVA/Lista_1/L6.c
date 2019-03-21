#include <stdio.h>
#include <stdlib.h>

int main () {
  int valorA,valorB,troca;
  printf("Digite dois números \n");
  scanf("%d", &valorA);
  scanf("%d", &valorB);
  troca = valorA;
  valorA = valorB;
  valorB = troca;
  printf("Troquei %d e %d\n", valorA, valorB);

  return 0;
}
