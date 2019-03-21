#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz {
  int linha;
  int coluna;
  int** mtz;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas) {
  if ((nlinhas > 0) && (ncolunas > 0)) {
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    mat->linha = nlinhas;
    mat->coluna = ncolunas;

    mat->mtz = (int**)malloc(sizeof(int*) * nlinhas);
    for(int i = 0; i < nlinhas; i++){
      mat->mtz[i] = (int*)malloc(sizeof(int) * ncolunas);
    }
    return mat;
  }
  printf("Erro: Número de linhas ou colunas invalido.\n");
  return NULL;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem) {
  if (mat == NULL) {
    printf("Erro: A matriz não existe.\n");
    return;
  }
  if ((linha > mat->linha) || (coluna > mat->coluna)) {
    printf("Erro: Linha ou coluna invalido.\n");
  } else {
      mat->mtz[linha][coluna] = elem;
  }
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {
  if (mat == NULL) {
    printf("Erro: A matriz não existe.\n");
    exit(1);
  }
  if ((linha > mat->linha) || (coluna > mat->coluna)) {
    printf("Erro: Linha ou coluna invalido.\n");
  } else {
      return mat->mtz[linha][coluna];
  }
}

int recuperaNColunas (Matriz* mat) {
  if (mat == NULL) {
    printf("Erro: A matriz não existe.\n");
    exit(1);
  }
  return mat->coluna;
}

int recuperaNLinhas (Matriz* mat) {
  if (mat == NULL) {
    printf("Erro: A matriz não existe.\n");
    exit(1);
  }
  return mat->linha;
}

Matriz* transposta (Matriz* mat) {
  if (mat == NULL) {
    printf("Erro: A matriz não existe.\n");
    exit(1);
  }
  Matriz* matT = inicializaMatriz(mat->linha, mat->coluna);
  for (int i=0; i < mat->linha; i++) {
    for (int j=0; j < mat->coluna; j++) {
      matT->mtz[i][j] = mat->mtz[j][i];
    }
  }
  return matT;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2) {
  if ((mat1 == NULL) || (mat2 == NULL)) {
    printf("Erro: A matriz não existe.\n");
    exit(1);
  }
  if ((mat1->linha == mat2->linha) && (mat1->coluna == mat2->coluna)) {
    Matriz* matM = inicializaMatriz(mat1->linha, mat1->coluna);
    for (int i=0; i < mat1->linha; i++) {
      for (int j=0; j < mat1->coluna; j++) {
        matM->mtz[i][j] = mat1->mtz[i][j] * mat2->mtz[i][j];
      }
    }
    return matM;
  }
  printf("Erro: Linha ou coluna invalido.\n");
  return NULL;
}

void imprimeMatriz(Matriz* mat) {
  if (mat == NULL) {
    printf("Erro: A matriz não existe.\n");
    return;
  }
  for (int i=0; i < mat->linha; i++) {
    for (int j=0; j < mat->coluna; j++) {
      printf("%d ", mat->mtz[i][j]);
    }
    printf("\n");
  }
}

void destroiMatriz(Matriz* mat) {
  if (mat == NULL) {
    printf("Erro: A matriz não existe.\n");
    return;
  }
  for (int i=0; i < mat->linha; i++) {
    free(mat->mtz[i]);
  }
  free(mat);
}
