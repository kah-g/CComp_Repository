#include <stdio.h>
#include <stdlib.h>

//vetores e alocacao dinamica
//nao fiz a multiplicacao com vetorzao pq e demais pra minha cabeca

float *transpostaA (int m, int n, float *matA);
float **transpostaB (int m, int n, float **matB);
float **multiplicaB (int m, int p, int n, float **mat1, float **mat2);

int main () {
  printf("Vamos brincar com matrizes!\n");
  printf("Entre com o tamanho da matriz.\n");
  int x, y;
  scanf("%d %d", &x, &y);
  printf("\n");
  printf("Vamos preencher a matriz de tamanho %dX%d com float.\n", x, y);
  //matriz em vetorzao
  float *matA = (float*) malloc (sizeof(float)*(x*y));
  for(int i=0; i < x*y; i++) {
    scanf("%f", &matA[i]);
  }
  //matriz com vetor com ponteiros para vetor
  float **matB = (float**) malloc (sizeof(float*)*x);
  for(int i=0; i < x; i++) {
    matB[i] = (float*) malloc (sizeof(float)*y);
  }
  int z = 0;
  for(int i=0; i < x; i++) {
    for(int j=0; j < y; j++) {
      matB[i][j] = matA[z];
      z++;
    }
  }
  printf("\nAgora vamos ver como ficou essa matriz:\n");
  printf("Matriz em vetor unico:\n");
  for(int i=0; i < x*y; i++) {
    printf("%.2f  ", matA[i]);
    if(i == y-1) {
      printf("\n");
    }
  }
  printf("\nMatriz com vetor de ponteiros para ponteiros:\n");
  for(int i=0; i < x; i++) {
    for(int j=0; j < y; j++) {
      printf("%.2f  ", matB[i][j]);
    }
    printf("\n");
  }
  float *matAT = transpostaA(x, y, matA);
  float **matBT = transpostaB(x, y, matB);
  printf("\nE a transposta fica assim:\n");
  printf("Matriz em vetor unico:\n");
  for(int i=0; i < x*y; i++) {
    printf("%.2f  ", matAT[i]);
    if(i == y-1) {
      printf("\n");
    }
  }
  printf("\n");
  printf("Matriz com vetor de ponteiros para ponteiros:\n");

  for(int i=0; i < x; i++) {
    for(int j=0; j < y; j++) {
      printf("%.2f  ", matBT[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("Agora vamos multiplicar essas matrizes e ver como fica:\n");
  if(x != y) {
    printf("Erro: Nao e possivel multiplicar essas matrizes.\n");
  } else {
    printf("\nMatriz com vetor de ponteiros para ponteiros:\n");
    float **matBM = multiplicaB(x,y,y,matB,matBT);
    for(int i=0; i < x; i++) {
      for(int j=0; j < y; j++) {
        printf("%.2f  ", matBM[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    for(int i=0; i < x; i++) {
      free(matBM[i]);
    }
    free(matBM);
  }

  free(matA);
  free(matAT);
  for(int i=0; i < x; i++) {
    free(matB[i]);
    free(matBT[i]);
  }
  free(matB);
  free(matBT);

  printf("Fim.\n");

  return 0;
}

float *transpostaA (int m, int n, float *matA) {
  float *Tmat = (float*) malloc(sizeof(float)*(m*n));
  for(int i=0; i < m; i++) {
    for(int j=0; j < n; j++) {
      Tmat[j*m+i] = matA[i*n+j];
    }
  }
  return Tmat;
}

float **transpostaB (int m, int n, float **matB) {
  float **Tmat = (float**) malloc (sizeof(float*)*n);
  for(int i=0; i < n; i++) {
    Tmat[i] = (float*) malloc (sizeof(float)*m);
  }
  for(int i=0; i < n; i++) {
    for(int j=0; j < m; j++) {
      Tmat[i][j] = matB[j][i];
    }
  }
  return Tmat;
}

float **multiplicaB (int m, int p, int n, float **mat1, float **mat2) {
  float **Mmat = (float**) malloc (sizeof(float*)*m);
  for(int i=0; i < m; i++) {
    Mmat[i] = (float*) malloc (sizeof(float)*n);
  }
  for(int i=0; i < m; i++) {
    for(int j=0; j < n; j++) {
      float aux = 0;
      for(int k=0; k < p; k++) {
        aux += mat1[i][k] * mat2[k][j];
      }
      Mmat[i][j] = aux;
    }
  }
  return Mmat;
}
