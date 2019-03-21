#include <stdio.h>
#include <stdlib.h>

int main () {
  int vA,vB;
  printf("Digite dois números \n");
  scanf("%d", &vA);
  scanf("%d", &vB);
  vA += vB;
  vB = vA - vB;
  vA -= vB;
  printf("Troquei %d e %d\n", vA, vB);

  return 0;
}
