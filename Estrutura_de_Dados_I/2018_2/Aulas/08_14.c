#include <stdio.h>
#include <stdlib.h>

int* TranspostaMatrizA (int matrizOriginal[3][3]);
int** TranspostaMatrizB (int matrizOriginal[3][3]);

int main () {
 //fazer a transposta da matriz usando as duas abordagens para alocar uma matriz dinamicamente
 //mas como eu sou ruim de álgebra linear vou so copiar a amtriz flw

  int k, l;

  //a matriz tem tamanho fixo 3x3
  //criando e preenchendo a matriz alocada estaticamente
  int matrizOriginal[3][3];
  printf("Entre com os %d elementos da matriz de numeros.\n", 9);
  for (k=0; k < 3; k++) {
    for (l=0; l < 3; l++) {
      scanf("%d", &matrizOriginal[k][l]);
    }
  }

  //printando a matriz criada
  printf("Matriz Criada:\n");
  for (k=0; k < 3; k++) {
    for (l=0; l < 3; l++) {
      printf("%d ", matrizOriginal[k][l]);
    }
    printf("\n");
  }

  printf("\n");

  //criando e alocando dinamicamente o vetor unidimensional que vai receber a matrizOriginal
  int* matrizCopiaA = TranspostaMatrizA (matrizOriginal);
  printf("Matriz copiada A:\n");
  for (k=0; k < 3; k++) {
    for (l=0; l < 3; l++) {
      printf("%d ", matrizCopiaA[k*3+l]);
    }
    printf("\n");
  }

  printf("\n");

  //criando e alocando dinamicamente o vetor de ponteiros que vai apontar para as linhas que vão receber a matrizOriginal
  int** matrizCopiaB = TranspostaMatrizB (matrizOriginal);
  printf("Matriz copiada B:\n");
  for (k=0; k < 3; k++) {
    for (l=0; l < 3; l++) {
      printf("%d ", matrizCopiaB[k][l]);
    }
    printf("\n");
  }

  //dando free nos mallocs
  free(matrizCopiaA);
  for (k=0; k < 3; k++) {
    free(matrizCopiaB[k]);
  }
  free(matrizCopiaB);
  return 0;
}

int* TranspostaMatrizA (int matrizOriginal[3][3]) {
  int* matrizCopia = (int*)malloc(sizeof(int)* 9);
  int a, b, c=0;
  for (a=0; a < 3; a++) {
    for (b=0; b < 3; b++) {
      matrizCopia[c] = matrizOriginal[b][a];
      c++;
    }
  }
  return matrizCopia;
}

int** TranspostaMatrizB (int matrizOriginal[3][3]) {
  //criando o ponteiro que aponta para o inicio de cada linha
  int** matrizPont = (int**)malloc(sizeof(int*) * 3);
  int i, j;

  //criando o vetor de cada linha
  for (i=0; i < 3; i++) {
    matrizPont[i] = (int*)malloc(sizeof(int) * 3);
  }

  //copiando o vetor
  for (i=0; i < 3; i++) {
    for (j=0; j < 3; j++) {
      matrizPont[i][j] = matrizOriginal[j][i];
    }
  }

  return matrizPont;

}
