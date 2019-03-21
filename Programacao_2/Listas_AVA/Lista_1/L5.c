#include <stdio.h>
#include <stdlib.h>

int main () {
  float f;
  printf("Digite um número: \n");
  scanf("%f", &f);
  f /= 5;
  printf("A quinta parte é: %f\n", f);

  return 0;
}
