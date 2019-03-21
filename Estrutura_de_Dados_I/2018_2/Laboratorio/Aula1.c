#include <stdlib.h>
#include <stdio.h>

#define PI 3.14

void calc_esfera (float r, float* area, float* volume);
int negativos (int n, float* vet);
void inverte (int n, int* vet);
int** inverte2 (int n, int* vet);

int main () {
  int exer;
  float* vet;
  int* vetor;
  int* vetorN;
  int i, t;
  printf("Qual o numero do exercicio?\n");
  scanf("%d", &exer);
  switch (exer) {
    case 1:
      //questao 1
      printf("Qual o raio da esfera?\n");
      float r;
      float area, volume;
      scanf("%f", &r);
      calc_esfera(r, &area, &volume);
      printf("Area: %.2f, Volume %.2f\n", area, volume);
      break;

    case 2:
      //questao 2
      printf("Qual o tamanho do vetor?\n");
      int n, neg;
      scanf("%d", &n);
      vet = (float*)malloc(sizeof(float) * n);
      printf("Entre com os dados do vetor.\n");
      for (i=0; i < n; i++) {
        scanf("%f", &vet[i]);
      }
      neg = negativos (n, vet);
      printf("Total de negativos no vetor: %d\n", neg);
      free(vet);
      break;

    case 3:
      //questao 3
      printf("Qual o tamanho do vetor?\n");
      int q;
      scanf("%d", &q);
      vetor = (int*)malloc(sizeof(int) * q);
      printf("Entre com os dados do vetor.\n");
      for (i=0; i < q; i++) {
        scanf("%d", &vetor[i]);
      }
      inverte (q, vetor);
      printf("Vetor invertido: ");
      for (i=0; i < q; i++) {
        printf("%d, ", vetor[i]);
      }
      printf("\n");
      free(vetor);
      break;

    case 4:
      //questao 4
      //int t;
      printf("Qual o tamanho do vetor?\n");
      scanf("%d", &t);
      printf("Entre com os dados do vetor.\n");
      vetorN = (int*)malloc(sizeof(int) * t);
      for (i=0; i < t; i++) {
        scanf("%d", &vetorN[i]);
      }
      int** vetorP;
      vetorP = inverte2 (t, vetorN);
      printf("Vetor invertido: ");
      for (i=0; i < t; i++) {
        printf("%d, ", *vetorP[i]);
      }
      printf("\n");
      free(vetorP);
      free(vetorN);
      break;

    default:
      //default
      printf("Opcao invalida");
      break;
  }

  return 0;

}

void calc_esfera (float r, float* area, float* volume) {
  *area = 4*PI*(r*r);
  *volume = (4*PI*(r*r*r))/3;
}

int negativos (int n, float* vet) {
  int i, neg=0;
  for (i=0; i < n; i++) {
    if (vet[i] < 0) {
      neg++;
    }
  }
  return neg;
}

void inverte (int n, int* vet) {
  int aux[n];
  int i, j=n;
  for (i=0; i < n; i++) {
    aux[j-1] = vet[i];
    j--;
  }
  for (i=0; i < n; i++) {
    vet[i] = aux[i];
  }
}

int** inverte2 (int n, int* vet) {
  int** vetorI = (int**)malloc(sizeof(int*) * n);
  int i, j, aux;
  for (i=0; i < n; i++) {
    vetorI[i] = &vet[i];
  }
  //bubble sort
  for (i=0; i < n; i++) {
    for (j=0; j < (n-i); j++) {
      if (*vetorI[j] > *vetorI[j+1]) {
        aux = *vetorI[j];
        *vetorI[j] = *vetorI[j+1];
        *vetorI[j+1] = aux;
      }
    }
  }
  return vetorI;
}
