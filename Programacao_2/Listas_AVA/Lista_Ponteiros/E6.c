#include <stdio.h>
#include <stdlib.h>

void LeDadosParaVetor (int *vet, int tam);

void ImprimiDadosDoVetor (int *vet, int tam);

void OrdeneCrescente (int *vet, int tam);

void TrocaNum (int *n1, int *n2);

int main () {
  int casos;

  scanf("%d", &casos);
  while (casos) {
    int tam;
    scanf("%d", &tam);

    int vet[tam];
    LeDadosParaVetor(vet, tam);

    OrdeneCrescente (vet, tam);

    ImprimiDadosDoVetor(vet, tam);

    casos--;
  }

  return 0;
}

void LeDadosParaVetor (int *vet, int tam) {
  int i, num;
  for (i=0; i < tam; i++) {
    scanf("%d", &num);
    *(vet+i) = num;
  }
}

void ImprimiDadosDoVetor (int *vet, int tam) {
  int i;
  for (i=0; i < tam; i++) {
    //printf("posicao: %d\n", i);
    printf("%d ", vet[i]);
  }
  printf("\n");
}

void OrdeneCrescente (int *vet, int tam) {
  //era pra ser um blubble sort
  int i, j;
    for (i=0; i < tam-1; i++) {
      for (j=0; j < ((tam-1)-i); j++) {
        if (vet[j] > vet[j+1]) {
          TrocaNum (&vet[j], &vet[j+1]);
        }
      }
    }
}

void TrocaNum (int *n1, int *n2) {
  int aux;
  aux = *n1;
  *n1 = *n2;
  *n2 = aux;
}
