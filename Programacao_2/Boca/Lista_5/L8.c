#include <stdio.h>
#include <stdlib.h>

void TrocaParEImpar (int *vet, int qtd);
void ImprimeDadosDoVetor (int *vet, int qtd);

int main () {
  int qN, i;
  scanf("%d", &qN);

  //lendo os numeros do vetor
  int nums[qN];
  for (i=0; i < qN; i++) {
    scanf("%d", &nums[i]);
  }

  TrocaParEImpar (nums, qN);
  ImprimeDadosDoVetor (nums, qN);

  return 0;
}

void TrocaParEImpar (int *vet, int qtd) {
  int i, aux;
  for (i=0; i < (qtd - 1); ) {
    aux = vet[i];
    vet[i] = vet[i+1];
    vet[i+1] = aux;

    i += 2;
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
