#include <stdio.h>
#include <stdlib.h>

int main () {
  int num,somaNeg=0,somaPos=0,totNeg=0,totPos=0;

  while ((scanf("%d", &num) == 1)) {
    if (num >= 0) {
      somaPos += num;
      totPos++;
    } else if (num < 0) {
      somaNeg += num;
      totNeg++;
    }
  }
  printf("%d %d %d %d\n", totNeg, totPos, somaNeg, somaPos);

  return 0;
}
