#include <stdio.h>
#include <stdlib.h>

int main () {
  float celsius, fahrenheit;
  printf("Digite a temperatura em Fahrenheit\n");
  scanf("%f", &fahrenheit);
  celsius = 5.0 * ((fahrenheit - 32) / 9.0);
  printf("Essa é a temperatura em Celsius: %2.f\n", celsius);

  return 0;
}
