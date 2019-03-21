#include <stdio.h>
#include <stdlib.h>

int main () {
  float celsius, kelvin;
  printf("Digite a temperatura em Kelvin\n");
  scanf("%f", &kelvin);
  celsius = kelvin - 273.15;
  printf("Essa é a temperatura em Celsius: %2.f\n", celsius);

  return 0;
}
