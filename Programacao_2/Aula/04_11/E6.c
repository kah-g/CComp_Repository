#include <stdio.h>
#include <stdlib.h>

int main () {
  //calculando o salario de fulaninho de acordo com o ano atual
  int aI = 2007, aA;
  printf("Entre com o ano atual\n");
  scanf("%d", &aA);
  float salI, pA;
  salI = 2000 + (2000 * 0.015);
  pA = 0.015 * 2;
  while (aI < aA) {
    salI += (salI * pA);
    pA *= 2;
    aI++;
  }
  printf("Salario Atual R$ %.2f\n", salI);

  return 0;
}
