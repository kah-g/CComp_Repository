#include <stdio.h>
#include <stdlib.h>

int main () {
  int n1, n2, n3, n4;
  int* pn1 = &n1;
  int* pn2 = &n2;
  int* pn3 = &n3;
  int* pn4 = &n4;
  printf("Hora de dar valores as variaveis!\n");
  scanf("%d %d %d %d", pn1, pn2, pn3, pn4);
  printf("Variaveis: n1:%d, n2:%d, n3:%d, n4:%d\n", n1, n2, n3, n4);

  return 0;
}
