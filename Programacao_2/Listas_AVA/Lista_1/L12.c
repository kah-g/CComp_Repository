#include <stdio.h>
#include <stdlib.h>

int main () {
  float k, m;
  printf("Digite a velocidade em milhas \n");
  scanf("%f", &m);
  k = 1.61 * m;
  printf("A velocidade é %2.1f k/h \n", k);

  return 0;
}
