#include <stdio.h>
#include <stdlib.h>

int main () {
  float celsius, fahrenheit;
  printf("Digite a temperatura em Celsius\n");
  scanf("%f", &celsius);
  fahrenheit = (celsius * (9.0/5.0)) + 32;
  printf("Essa é a temperatura em Fahrenheit: %f\n", fahrenheit);

  return 0;
}
