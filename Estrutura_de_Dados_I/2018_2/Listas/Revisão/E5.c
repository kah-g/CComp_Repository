#include <stdio.h>
#include <stdlib.h>

int main () {
  //alocar uma matriz de strings dinamicamente

  //criando e alocando a matriz
  char** matriz = (char**)malloc(sizeof(char*)*5);
  int i;
  for (i=0; i < 5; i++) {
    matriz[i] = (char*)malloc(sizeof(char)*70);
  }

  //lendo as strings
  printf("Entre com as 5 palavras. Tamanho máximo e 69 caracteres.\n");
  for (i=0; i < 5; i++) {
    scanf("%s", matriz[i]);
  }

  //imprimindo as strings
  for (i=0; i < 5; i++) {
    printf("Palavra %d: %s\n", i+1, matriz[i]);
  }

  //dando free
  for (i=0; i < 5; i++) {
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
