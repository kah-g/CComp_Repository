#include <stdio.h>
#include <stdlib.h>

//somar duas matrizes

int main () {
  int matA[2][3], matB[2][3], matC[2][3];
  int i, j;
  //recebendo os elementos das matrizes
  printf("Entre com a matriz A\n");
  for (i = 0;i < 2; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &matA[i][j]);
    }
  }
  printf("Entre com a matriz B\n");
  for (i = 0;i < 2; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &matB[i][j]);
    }
  }
  //somando as matrizes
  for (i = 0;i < 2; i++) {
    for (j = 0; j < 3; j++) {
      matC[i][j] = matA[i][j] + matB[i][j];
    }
  }
  printf("Matriz gerada a partir da soma de A e B\n");
  for (i = 0;i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", matC[i][j]);
    }
    printf("\n");
  }

  return 0;
}
