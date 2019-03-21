#include <stdio.h>
#include <stdlib.h>

int main () {
  float k, m;
  printf("Digite a velocidade em m/s \n");
  scanf("%f", &m);
  k = m * 3.6;
  printf("A velocidade é %2.1f k/h \n", k);

  return 0;
}
