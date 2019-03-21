#include <stdio.h>
#include <stdlib.h>

void Ordenador (int** ponteiro);

int main () {
  //armazenar 10 valores inteiros aleatorios, usar ponteiros para ordenar de forma crescente

  //criando o vetor
  int alt[10];

  //vetor de ponteiros
  int** pAlt = (int**)malloc(sizeof(int*)*10);

  //usando o random para preencher o vetor
  int r, i;
  printf("Entre com o um numero inteiro: \n");
  scanf("%d", &r);
  srand(r);
  for (i=0; i < 10; i++) {
    alt[i] = rand () % 100;
  }

  //imprimindo o vetor desordenado
  printf("Vetor desordenado:\n");
  for (i=0; i < 10; i++) {
    printf("%d ", alt[i]);
  }
  printf("\n");

  //ligandos os vetores aos ponteiros
  for (i=0; i < 10; i++) {
    pAlt[i] = &alt[i];
  }

  //ordenando
  Ordenador(pAlt);

  //imprimindo o ponteiro ordenado
  printf("Ponteiro ordenado:\n");
  for (i=0; i < 10; i++) {
    printf("%d ", *pAlt[i]);
  }
  printf("\n");

  free(pAlt);

  return 0;
}

void Ordenador (int** ponteiro) {
  //bubble sort, nao esquececa
  int i,j, aux;
  for (i=0; i < 10; i++) {
    for (j=0; j < 10 - i - 1; j++) {
      if (*ponteiro[j] > *ponteiro[j+1]) {
        aux = *ponteiro[j];
        *ponteiro[j] = *ponteiro[j+1];
        *ponteiro[j+1] = aux;
      }
    }
  }
}
