#include <stdio.h>
#include <stdlib.h>

int main () {
  //Listar n numeros impares
  int n,c,i=1;
  printf("Entre com a quantidade\n");
  scanf("%d", &n);
  for (c=1; c <= n; c++) {
    printf("%d\n", i);
    i += 2;
  }

  return 0;
}
