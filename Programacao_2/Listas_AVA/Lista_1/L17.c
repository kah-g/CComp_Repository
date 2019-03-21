#include <stdio.h>
#include <stdlib.h>

int main () {
  int dt,qb;
  float p,ql;
  printf("Informe o número de dias trabalhados \n");
  scanf("%d", &dt);
  qb = 30 * dt;
  p = qb * 0.08;
  ql = qb - p;
  printf("A quantia líquida a ser recebida é: %f\n", ql);

  return 0;
}
