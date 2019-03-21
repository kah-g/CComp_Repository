#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
  float soma=0,op=0;
  int k=1, n;
  scanf("%d", &n);
  while (k <= n) {
    op = 6.0/(k*k);
    soma += op;
    k+=1;
    //printf("%f\n", op);
  }
  soma = sqrt (soma);
  printf("%.6f\n", soma);

  return 0;
}
