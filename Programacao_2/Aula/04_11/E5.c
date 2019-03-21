#include <stdio.h>
#include <stdlib.h>

int main () {
  //calculando o tempo que z leva para ficar mais alto que c, tendo suas alturas e o quanto crescem por ano
  float ac=1.5, az=1.1, cc=0.02, cz=0.03;
  int a=1;
  while (ac>=az) {
    ac += cc;
    az +=  cz;
    a += 1;
  }
  printf("Ziraldo levou %d anos para ficar mais alto que Arnaldo\n", a);
  printf("Altura Ziraldo: %.2f. Altura Arnaldo: %.2f\n", az, ac);

  return 0;
}
