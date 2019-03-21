#include <stdio.h>
#include <stdlib.h>

int main () {
  //imprimir numeros de 1 a 100 utilizando for, while e do-while
  int i, i2=1, i3=1;

  for (i=1; i<=100; i++) {
    printf("Usando for: %d\n", i);
  }

while (i2<=100) {
  printf("Usando while: %d\n", i2);
  i2++;
}

do {
  printf("Usando do-while: %d\n", i3);
  i3++;
} while (i3<=100);

  return 0;
}
