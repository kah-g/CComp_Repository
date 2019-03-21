#include <stdio.h>
#include <stdlib.h>

int TrocaInteiros (int n1, int n2);

int main () {
  int n1, n2;
  while (scanf("%d %d", &n1, &n2) == 2) {
    if (TrocaInteiros(n1, n2) == 1) {
      printf("TROCADO: %d %d\n", n1, n2);
    } else {
      printf("ORIGINAL: %d %d\n", n1, n2);
    }
  }
  return 0;
}

int TrocaInteiros (int n1, int n2) {
  if (n1 >= n2) {
    int *n1P = &n1, *n2P = &n2;
    int aux = *n1P;
    *n1P = *n2P;
    *n2P = aux;
    return 1;
  } else {
    return 0;
  }
}
