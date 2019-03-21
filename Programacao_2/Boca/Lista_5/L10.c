#include <stdlib.h>
#include <stdio.h>

void OrdenaCrescente (int *vet, int qtd);
void ImprimeDadosDoVetor (int *vet, int qtd);

int main () {
  int qN, i;
  scanf("%d", &qN);

  //lendo os numeros do vetor
  int nums[qN];
  for (i=0; i < qN; i++) {
    scanf("%d", &nums[i]);
  }

  OrdenaCrescente (nums, qN);
  ImprimeDadosDoVetor (nums, qN);

  return 0;
}

void OrdenaCrescente (int *vet, int qtd) {
  int i, aux, j;
  //i percorre o elemento pelo vetor
  //j percorre o vetor todo

  for (j=0; j < qtd; j++) {
    for (i=0; i < ((qtd - j) - 1); i++) {
      if (vet[i] > vet[i+1]) {
        aux = vet[i];
        vet[i] = vet[i+1];
        vet[i+1] = aux;
      }
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
