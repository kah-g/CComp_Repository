#include <stdio.h>
#include <stdlib.h>

int main () {
  //verificar qual numero e maior com aquele if retardado
  int x,y,z;
  printf("Entre com 2 números \n");
  scanf("%d", &x);
  scanf("%d", &y);
  z = x>y?x:y;
  printf("O maior número é: %d\n", z);

  return 0;
}
