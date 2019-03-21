#include <stdio.h>
#include <stdlib.h>

#define TAM 8

void PreencheArray (int *lista, int num, int tam);

void ImprimeArray (int *lista, int tam);

int main () {
  int lista[TAM];
  int num=32;
  PreencheArray (lista, num, TAM);
  ImprimeArray(lista, TAM);

  return 0;
}

void PreencheArray (int *lista, int num, int tam) {
  int i;
  for (i=0; i < tam; i++) {
    *(lista+i) = num;
  }
}

void ImprimeArray (int *lista, int tam) {
  int i;
  for (i=0;i < tam; i++) {
    printf("%d ", lista[i]);
  }
  printf("\n");
}
