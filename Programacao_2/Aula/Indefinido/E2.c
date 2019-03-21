#include "E2.h"

//usando o tipo definido estudante, criar uma lista com 5 estudantes e ver qual tem o maior coeficiente

float MaiorCoeficiente (estudante *turmaA);

int main () {
  //criando o array de estudantes
  estudante turmaA[5];

  //criando os estudantes
  turmaA[0] = {21, 101, 6.2};
  turmaA[1] = {19, 102, 9.1};
  turmaA[2] = {25, 103, 5.9};
  turmaA[3] = {31, 104, 3.7};
  turmaA[4] = {18, 105, 2.8};

  printf("O maior coeficiente é: %.1f\n", MaiorCoeficiente(turmaA));

  return 0;
}

float MaiorCoeficiente (estudante *turmaA) {
  float maior=0.0;
  int i;
  for (i = 0; i < 5; i++) {
    if (turmaA[i].coeficiente > maior) {
      maior = turmaA[i].coeficiente;
    }
  }

  return maior;
}
