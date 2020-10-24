#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

struct matriz {
  int linhas;
  int colunas;
  int** mtz;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas) {
  if (nlinhas > 0 && ncolunas > 0) {
    Matriz* mat01 = (Matriz*) malloc (sizeof (Matriz));
    mat01->linhas = nlinhas;
    mat01->colunas = ncolunas;
    mat01->mtz = (int**) malloc (sizeof(int*)*nlinhas);
    for (int i=0; i < nlinhas; i++) {
      mat01->mtz[i] = (int*) malloc (sizeof(int)*ncolunas);
    }
    return mat01;
  } else {
    printf("Erro: Numero de linhas ou colunas invalido.\n");
    return NULL;
  }
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem) {
  if (mat != NULL) {
    if ((linha >= 0 && linha <= mat->linhas) && (coluna >= 0 && coluna <= mat->colunas)) {
      mat->mtz[linha][coluna] = elem;
    } else {
      printf("Erro: Linha ou coluna invalida.\n");
    }
  } else {
    printf("Erro: Matriz nula.\n");
  }
}

int recuperaElemento (Matriz* mat, int linha, int coluna) {
  if (mat != NULL) {
    if ((linha >= 0 && linha <= mat->linhas) && (coluna >= 0 && coluna <= mat->colunas)) {
      return mat->mtz[linha][coluna];
    } else {
      printf("Erro: Linha ou coluna invalida.\n");
      return NULL;
    }
  } else {
    printf("Erro: Matriz nula.\n");
    return NULL;
  }
}

int recuperaNColunas (Matriz* mat) {
  if (mat != NULL) {
    return mat->colunas;
  } else {
    printf("Erro: Matriz nula.\n");
    return NULL;
  }
}

int recuperaNLinhas (Matriz* mat) {
  if (mat != NULL) {
    return mat->linhas;
  } else {
    printf("Erro: Matriz nula.\n");
    return NULL;
  }
}

Matriz* transposta (Matriz* mat) {
  if (mat != NULL) {
    Matriz* matT = inicializaMatriz (mat->colunas, mat->linhas);
    for (int i=0; i < mat->colunas; i++) {
      for (int j=0; j < mat->linhas; j++) {
        modificaElemento (matT, i, j, mat->mtz[j][i]);
      }
    }
    return matT;
  } else {
    printf("Erro: Matriz nula.\n");
    return NULL;
  }
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2) {
  if (mat1 != NULL && mat2 != NULL) {
    if (mat1->colunas == mat2->linhas) {
      Matriz* matX = inicializaMatriz (mat1->linhas, mat2->colunas);
      int p = mat1->colunas; //que deve ser igual ao numero de linhas de mat2, como verificado antes
      for (int i=0; i < mat1->linhas; i++) {
        for (int j=0; j <mat2->colunas; j++) {
          int resultado = 0;
          for (int k=0; k < p; k++) {
            resultado = mat1->mtz[i][k] * mat2->mtz[k][j];
          }
          modificaElemento (matX, i, j, resultado);
        }
      }
      return matX;
    } else {
      printf("Erro: O numero de colunas de mat1 não corresponde ao numero de linhas de mat2.\n");
    }
  } else {
    printf("Erro: Matriz nula.\n");
    return NULL;
  }
}

void imprimeMatriz(Matriz* mat) {
  if (mat != NULL) {
    for (int i=0; i < mat->linhas; i++) {
      for (int j=0; j < mat->colunas; j++) {
        printf("%d ", mat->mtz[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  } else {
    printf("Erro: Matriz nula.\n");
  }
}

void destroiMatriz(Matriz* mat) {
  if (mat != NULL) {
    for (int i=0; i < mat->linhas; i++) {
      free(mat->mtz[i]);
    }
    free(mat->mtz);
    free(mat);
  } else {
    printf("Erro: Matriz nula.\n");
  }
}
