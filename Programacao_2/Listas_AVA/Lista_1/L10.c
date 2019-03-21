#include <stdio.h>
#include <stdlib.h>

int main () {
  float k, m;
  printf("Digite a velocidade em km/h \n");
  scanf("%f", &k);
  m = k / 3.6;
  printf("Essa é a velocidade em m/s: %2.1f\n", m);

  return 0;
}
