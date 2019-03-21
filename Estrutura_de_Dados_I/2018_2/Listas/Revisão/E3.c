#include <stdio.h>
#include <stdlib.h>

int main () {
  //ler 10 numeros inteiros e armazena-los em uma matriz, e utilizar ponteiros para imprimi-los

  //criando a matriz
  int matriz[2][5];
  int i, j;
  int* p;

  //lendo os elementos da matriz
  printf("Entre com 10 numeros inteiros.\n");
  for (i=0; i < 2; i++) {
    for (j=0; j < 5; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  //associando o ponteiro a matriz
  p = *matriz;

  //imprimindo pelo ponteiro
  for (i=0; i < 10; i++) {
    printf("%d ", *p);
    p++;
  }
  printf("\n");

  return 0;
}
