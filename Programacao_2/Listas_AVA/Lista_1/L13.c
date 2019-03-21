#include <stdio.h>
#include <stdlib.h>

int main () {
  float k, m;
  printf("Digite a velocidade em k/h \n");
  scanf("%f", &k);
  m = 1.61 / k;
  printf("A velocidade é %f milhas \n", m);

  return 0;
}
