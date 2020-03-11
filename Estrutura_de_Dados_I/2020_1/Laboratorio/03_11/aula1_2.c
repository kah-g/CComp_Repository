#include <stdio.h>
#include <stdlib.h>

void calc_esfera (float r, float* area, float* volume);
void fatorial (int n, int* f);
int negativos (int n, float* vet);
void inverte (int n, int* vet);

int main () {
  printf("Escolha o exercicio que vc quer rodar:\n");
  printf("1-Calculo de area.\n2-Calculo de fatorial.\n3-Negativos.\n4-Inverter.\n");
  int op;
  scanf("%d", &op);
  switch (op) {
    case 1:
      printf("Entre com o raio da esfera:\n");
      float raio;
      float* area = (float*) malloc (sizeof(float));
      float* volume = (float*) malloc (sizeof(float));
      scanf("%f", &raio);
      calc_esfera (raio, area, volume);
      printf("Area da esfera: %f  -  Volume da esfera: %f\n", *area, *volume);
      free(area);
      free(volume);
    break;

    case 2:
      printf("Entre com um numero inteiro positivo:\n");
      int numero;
      int* fat = (int*) malloc (sizeof(int));
      scanf("%d", &numero);
      if (numero < 1) {
        do {
          printf("O numero deve ser um inteiro positivo.\n");
          scanf("%d", &numero);
        }while (numero < 1);
      }
      fatorial (numero, fat);
      printf("O fatorial de %d eh: %d.\n", numero, *fat);
      free(fat);
    break;

    case 3:
      printf("Defina o tamanho do vetor:\n");
      int tam;
      scanf("%d", &tam);
      if (tam < 1) {
        printf("O tamanho entrado nao eh valido. O tamanho padrao eh 3.\n");
        tam = 3;
      }
      float* vetor = (float*) malloc (sizeof(float)*tam);
      //float vetor[tam];
      printf("Preencha o vetor.\n");
      for (int i=0; i < tam; i++) {
        scanf("%f", &vetor[i]);
      }
      int neg = negativos (tam, vetor);
      printf("Ha %d numeros negativos no vetor.\n", neg);
      free(vetor);
    break;

    case 4:
      printf("Defina o tamanho do vetor:\n");
      int tam2;
      scanf("%d", &tam2);
      if (tam2 < 1) {
        printf("O tamanho entrado nao eh valido. O tamanho padrao eh 3.\n");
        tam2 = 3;
      }
      int* vetor2 = (int*) malloc (sizeof(int)*tam2);
      printf("Preencha o vetor.\n");
      for (int i=0; i < tam2; i++) {
        scanf("%d", &vetor2[i]);
      }
      inverte (tam2, vetor2);
      printf("Vetor apos inversao: ");
      for (int i=0; i < tam2; i++) {
        printf("%d ", *(vetor2+i));
      }
      printf("\n");
      free(vetor2);
    break;

    default:
      printf("Valor invalido!\n");
  }

  return 0;
}

void calc_esfera (float r, float* area, float* volume) {
  float pi = 3.14;
  *area = 4*(pi*(r*r));
  *volume = (4*(pi*(r*r*r)))/3;
}

void fatorial (int n, int* f) {
  *f = 0;
  for (int i=0; i < n+1; i++) {
    *f += i;
  }
}

int negativos (int n, float* vet) {
  int total = 0;
  for (int i=0; i < n; i++) {
    if (vet[i] < 0) {
      total += 1;
    }
  }
  return total;
}

void inverte (int n, int* vet) {
  int aux[n];
  for (int i=0; i < n; i++) {
    aux[i] = vet[i];
  }
  for (int i=0; i < n; i++) {
    vet[i] = aux[(n-i)-1];
  }
}
