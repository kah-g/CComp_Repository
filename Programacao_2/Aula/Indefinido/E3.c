#include <stdio.h>
#include <stdlib.h>

int main () {
  int matriz[3][3];
  int i, j, soma=0;
  printf("Entre com os elementos da matriz 3x3\n");
  //lendo os elementos da matriz
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }
  //somando os elementos da matriz
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      soma = soma + matriz[i][j];
    }
  }
  printf("A soma dos elementos da matriz é: %d\n", soma);

  return 0;
}
