#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
  int a, b;
  float r, aR, bR;
  scanf("%d %d", &a, &b);
  aR = sqrt (a);
  bR = sqrt (b);
  r = aR + bR;
  printf("%.2f\n", r);

  return 0;
}
