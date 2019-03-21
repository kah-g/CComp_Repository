#include <stdio.h>
#include <stdlib.h>

int TrocaInteiros (int *n1, int *n2);

int main () {
  int n1, n2;
  while (scanf("%d %d", &n1, &n2) == 2) {
    if (TrocaInteiros(&n1, &n2)) {
      printf("TROCADO: %d %d\n", n1, n2);
    } else {
      printf("ORIGINAL: %d %d\n", n1, n2);
    }
  }

  return 0;
}

int TrocaInteiros (int *n1, int *n2) {
  if (*n1 > *n2) {
    int aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;

    return 1;
  } else {

    return 0;
  }
}
