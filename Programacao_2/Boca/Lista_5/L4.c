#include <stdio.h>
#include <stdlib.h>

int VerificaIntervalo (int num, int interA, int interB);

int main () {
  int qNum, i, interA, interB, c;
  //lendo a quantidade
  scanf("%d", &qNum);
  int nums[qNum];

  //lendo os numeros
  for (i=0; i < qNum; i++) {
    scanf("%d", &nums[i]);
  }

  //lendo o intervalo
  scanf("%d %d", &interA, &interB);

  int interIn=0, interOut=0;
  //passando os numeros para verificar se estao no intervalo
  for (i=0; i < qNum; i++) {
    c = VerificaIntervalo(nums[i], interA, interB);
    if (c == 1) {
      interIn++;
    } else if (c == 0) {
      interOut++;
    }
  }
  printf("%d %d\n", interIn, interOut);

  return 0;
}

int VerificaIntervalo (int num, int interA, int interB) {
  if ((num >= interA) && (num <= interB)) {
    return 1;
  } else {
    return 0;
  }
}
