#include <stdio.h>
#include <stdlib.h>

int VerificaN1 (int qN1, int qN2, int *num1, int *num2);
int VerificaNum (int num, int qN2, int *num2);

int main () {
  int qN1, qN2, i, c;
  //lendo o tamanho e percorrendo o vetor N1
  scanf("%d", &qN1);
  int num1[qN1];
  for (i=0; i < qN1; i++) {
    scanf("%d", &num1[i]);
  }

  //lendo o tamanho e percorrendo o vetor N2
  scanf("%d", &qN2);
  int num2[qN2];
  for (i=0; i < qN2; i++) {
    scanf("%d", &num2[i]);
  }

  c = VerificaN1 (qN1, qN2, num1, num2);

  if (c == 0) {
    printf("NENHUM\n");
  } else if (c == qN1) {
    printf("TODOS\n");
  } else if (c < qN1) {
    printf("PARCIAL\n");
  }

  return 0;
}

int VerificaN1 (int qN1, int qN2, int *num1, int *num2) {
  //c e o contador de quantos numeros de N1 estao em N2
  int i, c=0;
  for (i=0; i < qN1; i++) {
    c += VerificaNum (num1[i], qN2, num2);
  }

  return c;
}

int VerificaNum (int num, int qN2, int *num2) {
  int i;
  for (i=0; i < qN2; i++) {
    if (num == num2[i]) {
      //retorna 1 quando acha num no vetor 2
      return 1;
    }
  }
  //retorna 1 quando nao acha num no vetor 2
  return 0;
}
