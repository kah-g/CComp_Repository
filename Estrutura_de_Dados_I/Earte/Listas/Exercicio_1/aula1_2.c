#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera (float r, float* area, float* volume);
int raizes (float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);

/*int main () {
  //2.1
  printf("Entre com o raio da esfera:\n");
  float raio;
  scanf("%f", &raio);
  float* area = (float*) malloc (sizeof (float));
  float* volume = (float*) malloc (sizeof (float));
  calc_esfera (raio, area, volume);
  printf("Resultados: Area %f, Volume %f\n", *area, *volume);
  free(area);
  free(volume);

  return 0;
}*/

/*int main () {
  //2.2
  printf("Entre com os valores de a, b e c:\n");
  float a,b,c;
  scanf("%f %f %f", &a, &b, &c);
  float* x1 = (float*) malloc (sizeof (float));
  float* x2 = (float*) malloc (sizeof (float));
  int r = raizes (a, b, c, x1, x2);
  printf("Resultados: raizes %d, x1 %f, x2 %f\n", r, *x1, *x2);
  free(x1);
  free(x2);

  return 0;
}*/

/*int main () {
  //2.3
  printf("Escolha o tamanho do vetor:\n");
  int n;
  scanf("%d", &n);
  printf("Preencha o vetor.\n");
  int* vetor = (int*) malloc (sizeof (int)*n);
  for (int i=0; i < n; i++) {
    scanf("%d", &vetor[i]);
  }
  int t_pares = pares (n, vetor);
  printf("Total de pares no vetor: %d\n", t_pares);
  free (vetor);

  return 0;
}*/

int main () {
  //2.4
  printf("Escolha o tamanho do vetor:\n");
  int n;
  scanf("%d", &n);
  printf("Preencha o vetor.\n");
  int* vetor = (int*) malloc (sizeof (int)*n);
  for (int i=0; i < n; i++) {
    scanf("%d", &vetor[i]);
  }
  inverte (n, vetor);
  printf("Vetor invertido:\n");
  for (int i=0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
  free(vetor);

  return 0;
}

void calc_esfera (float r, float* area, float* volume) {
  float pi = 3.14;
  *area = 4 * (pi * (r*r));
  *volume = (4*(pi*(r*r*r))) / 3;
}

int raizes (float a, float b, float c, float* x1, float* x2) {
  int delta = (b*b) - 4 * a * c;
  if (delta < 0) {
    return 0;
  }
  float r_delta = sqrt (delta);
  *x1 = ((-b) + r_delta) / (2 * a);
  *x2 = ((-b) - r_delta) / (2 * a);
  if (delta == 0) {
    return 1;
  } else {
    return 2;
  }
}

int pares (int n, int* vet) {
  int total = 0;
  for (int i=0; i < n; i++) {
    if ((vet[i] % 2) == 0) {
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
