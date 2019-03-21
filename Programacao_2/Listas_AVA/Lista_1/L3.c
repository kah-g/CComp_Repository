#include <stdio.h>
#include <stdlib.h>

int main () {
  int a,b,c,d;
  printf("Digite três números\n");
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  d = a+b+c;
  printf("A soma dos três números é: %d\n", d);

  return 0;
}
