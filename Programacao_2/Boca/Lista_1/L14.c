#include <stdio.h>
#include <stdlib.h>

int main () {
  int xa, ya, xb, yb, xp, yp;
  int vxa, vxb, vya, vyb;
  scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xp, &yp);
  //testando eixo x
  if (xa <= xb) {
    if ((xp >= xa) && (xp <= xb)) {
      vxa = 1;
    } else {
      vxa = 0;
    }
  } else {
    if ((xp >= xb) && (xp <= xa)) {
      vxb = 1;
    } else {
      vxb = 0;
    }
  }
  //testando eixo b
  if (ya <= yb) {
    if ((yp >= ya) && (yp <= yb)) {
      vya = 1;
    } else {
      vya = 0;
    }
  } else {
    if ((yp >= yb) && (yp <= ya)) {
      vyb = 1;
    } else {
      vyb = 0;
    }
  }
  //testando se esta no retangulo
  if (((vxa == 1) || (vxb == 1)) && ((vya == 1) || (vyb == 1))) {
    printf("Dentro\n");
  } else {
    printf("Fora\n");
  }
  return 0;
}
