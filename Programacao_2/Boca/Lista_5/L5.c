#include <stdio.h>
#include <stdlib.h>

int ProcuraNums (int numX, int numQ, int *nums);

int main () {
  int numX, numQ, i;
  //o numero X
  scanf("%d", &numX);
  //a quantidade de numeros
  scanf("%d", &numQ);

  int nums[numQ];
  //lendo o vetor de numeros
  for (i=0; i < numQ; i++) {
    scanf("%d", &nums[i]);
  }

  printf("RESP:%d\n", ProcuraNums(numX, numQ, nums));

  return 0;
}

int ProcuraNums (int numX, int numQ, int *nums) {
  int i;
  for (i=0; i < numQ; i++) {
    if (numX == nums[i]) {
      //retorna a posicao do vetor onde esta X
      return i;
    }
  }
  //se nao estiver retorna o tamanho do vetor
  return numQ;
}
