#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Retornar um vetor com n numeros aleatorios

int* Sorteio (int n);

int main () {
  int n;
  printf("Entre com a quantidade de numeros a serem gerados.\n");
  scanf("%d", &n);
  int *p = Sorteio(n);
  for (int i = 0; i < n; i++) {
    printf("%d\n", p[i]);
  }
  free(p);
}

int* Sorteio (int n) {
  int* x = (int*) malloc (sizeof(int)*n);
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    x[i] = rand() %61;
  }
  return x;
}
