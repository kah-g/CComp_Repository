#include <stdio.h>
#include <stdlib.h>

int Crescente (int partN, int *notas);
int Decrescente (int partN, int *notas);
int Igual (int partN, int *notas);

int main () {
  int partN, i;
  scanf("%d", &partN);
  int notas[partN];
  for (i=0; i < partN; i++) {
    scanf("%d", &notas[i]);
  }
  if (partN == 1) {
    //verifica se o tamanho do vetor e 1
    printf("CRESCENTE&DECRESCENTE\n");
  } else {
    if ((Crescente (partN, notas)) != 0) {
      printf("CRESCENTE\n");
    } else if ((Decrescente (partN, notas)) != 0) {
      printf("DECRESCENTE\n");
    } else if ((Igual (partN, notas)) != 0) {
      printf("CRESCENTE&DECRESCENTE\n");
    } else {
      printf("DESORDENADO\n");
    }
  }

  return 0;
}

int Crescente (int partN, int *notas) {
  int cres=0, i;
  //verifica se e crescente
  for (i=0; i < (partN - 1); i++) {
    if (notas[i] < notas[i+1]) {
      cres++;
    } else {
      cres = 0;
      break;
    }
  }

  return cres;
}

int Decrescente (int partN, int *notas) {
  int decres=0, i;
  //verifica se e decrescente
  for (i=0; i < (partN - 1); i++) {
    if (notas[i] > notas[i+1]) {
      decres++;
    } else {
      decres = 0;
      break;
    }
  }

  return decres;
}

int Igual (int partN, int *notas) {
  int igual=0, i;
  //verifica se sao iguais
  for (i=0; i < (partN - 1); i++) {
    if (notas[i] == notas[i+1]) {
      igual++;
    } else {
      igual = 0;
      break;
    }
  }

  return igual;
}
