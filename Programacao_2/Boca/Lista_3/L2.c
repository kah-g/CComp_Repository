#include <stdio.h>
#include <stdlib.h>

float Soma (float num1, float num2);
float Subtracao (float num1, float num2);
float Divisao (float num1, float num2);
float Multiplacao (float num1, float num2);
float Calcular (float num1, float num2, char operador);

//como fazer essa desgralha????

int main () {
  float num1, num2, resultado;
  char operador;
  scanf("%f %f %c", &num1, &num2, &operador);
  resultado = Calcular (num1, num2, operador);
    while (scanf("%f %c", &num2, &operador) == 2) {
      num1 = resultado;
      resultado = Calcular (num1, num2, operador);
  }
    printf("%.2f\n", resultado);

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

float Calcular (float num1, float num2, char operador) {
  float resultado;
  if (operador == '+') {
    resultado = Soma (num1, num2);
  }
  if (operador == '-') {
    resultado = Subtracao (num1, num2);
  }
  if (operador == '*') {
    resultado = Multiplacao (num1, num2);
  }
  if (operador == '/') {
    resultado = Divisao (num1, num2);
  }

  return resultado;
}
