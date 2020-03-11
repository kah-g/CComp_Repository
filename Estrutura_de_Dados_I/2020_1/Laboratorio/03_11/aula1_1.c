#include <stdio.h>
#include <stdlib.h>

int main () {
  int a1, a2, a3, a4;
  //int* p1, p2, p3, p4;
  int* p1 = &a1;
  int* p2 = &a2;
  int* p3 = &a3;
  int* p4 = &a4;
  printf("Entre com 4 valores inteiros:\n");
  scanf("%d %d %d %d", p1, p2, p3, p4);
  printf("Variaveis modificadas: a1: %d, a2: %d, a3: %d, a4: %d.\n", a1, a2, a3, a4);

  return 0;
}
