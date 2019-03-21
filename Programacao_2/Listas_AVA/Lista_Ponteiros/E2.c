#include <stdio.h>
#include <stdlib.h>

int main () {
  int a,b, *pA, *pB;
  pA = &a;
  pB = &b;
  if (pA > pB) {
    printf("Endereço de A maior que de B\n");
  } else {
    printf("Endereço de B maior que de A\n");
  }

  return 0;
}
