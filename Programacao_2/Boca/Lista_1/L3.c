#include <stdio.h>
#include <stdlib.h>

int main () {
  float iex, iey, sdx, sdy, pe;
  scanf("%f %f %f %f", &iex, &iey, &sdx, &sdy);
  pe = ((sdx - iex)*2) + ((sdy - iey)*2);
  printf("%.2f\n", pe);

  return 0;
}
