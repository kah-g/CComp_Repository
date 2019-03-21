#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pi = 3.141592;

int main () {
  float raio, area, metadeArea;
  scanf("%f", &raio);
  area = pi * (raio*raio);
  metadeArea = sqrt((area/2)/pi);
  printf("%.2f %.2f\n", area, metadeArea);

  return 0;
}
