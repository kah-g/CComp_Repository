#include <stdio.h>
#include <stdlib.h>

void InverteVetor (int *vet, int qtd);
void ImprimeDadosDoVetor (int *vet, int qtd);

int main () {
  int qN, i;
  scanf("%d", &qN);

  int nums[qN];
  for (i=0; i <qN; i++) {
    scanf("%d", &nums[i]);
  }

  InverteVetor (nums, qN);
  ImprimeDadosDoVetor (nums, qN);

  return 0;
}

void InverteVetor (int *vet, int qtd) {
  int i, aux;
  if (qtd == 2) {
    aux = vet[0];
    vet[0] = vet[1];
    vet[1] = aux;
  } else if (qtd == 1){
    return;
  } else {
    for (i=0; i < (qtd / 2); i++) {
      aux = vet[i];
      vet[i] = vet[qtd - (i+1)];
      vet[qtd - (i+1)] = aux;
    }
  }
}

void ImprimeDadosDoVetor (int *vet, int qtd) {
  int i;
  printf("{");
  for (i=0; i < qtd; i++) {
    if (i == (qtd - 1)) {
      printf("%d", vet[i]);
    } else {
      printf("%d, ", vet[i]);
    }
  }
  printf("}");
  printf("\n");
}
