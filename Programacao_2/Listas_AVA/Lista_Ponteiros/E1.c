#include <stdio.h>
#include <stdlib.h>

int main () {
  int num, *pNum;
  char letra, *pLetra;
  float numQ, *pNumQ;

  pNum = &num;
  pLetra = &letra;
  pNumQ = &numQ;

  *pNum = 10;
  *pLetra = 'c';
  *pNumQ = 5.2;

  printf("Imprimindo as posições: inteiro-%p caractere-%p float-%p\n", pNum, pLetra, pNumQ);
  printf("Imprimindo os valores: inteiro-%d caractere-%c float-%f\n", *pNum, *pLetra, *pNumQ);

  return 0;
}
