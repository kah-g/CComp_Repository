#include <stdio.h>
#include <stdlib.h>

float Soma (float num1, float num2);
float Subtracao (float num1, float num2);
float Divisao (float num1, float num2);
float Multiplacao (float num1, float num2);

int main () {
  float num1, num2;
  while (scanf("%f %f", &num1, &num2) == 2) {
    float result;
    result = Soma(num1, num2);
    printf("%.2f ", result);
    result = Subtracao(num1, num2);
    printf("%.2f ", result);
    result = Divisao (num1, num2);
    printf("%.2f ", result);
    result = Multiplacao (num1, num2);
    printf("%.2f ", result);
    printf("\n");
  }

  return 0;
}

float Soma (float num1, float num2) {
  float resultado;
  resultado = num1 + num2;

  return resultado;
}

float Subtracao (float num1, float num2) {
  float resultado;
  resultado = num1 - num2;

  return resultado;
}

float Divisao (float num1, float num2) {
  float resultado;
  resultado = num1 / num2;

  return resultado;
}

float Multiplacao (float num1, float num2) {
  float resultado;
  resultado = num1 * num2;

  return resultado;
}
