#include <stdio.h>
#include <stdlib.h>

int main () {
  int num;
  float teste;
  scanf("%d", &num);
  teste = num%2;
  if (teste != 0) {
    printf("Impar\n");
  } else {
    printf("Par\n");
  }

  return 0;
}
