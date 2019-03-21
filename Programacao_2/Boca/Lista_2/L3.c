#include <stdio.h>
#include <stdlib.h>

int main () {
  int q,n,c,menor=9999,maior=-9999,pares=0,impares=0;
  float media=0;
  scanf("%d", &q);
  for (c=0; c!=q;c++) {
    scanf("%d", &n);
    if (n > maior) {
      maior = n;
    }
    if (n < menor) {
      menor = n;
    }
    if ((n%2) == 0) {
      pares += 1;
    }
    if ((n%2) != 0) {
      impares += 1;
    }
    media += n;
  }
  media /= q;
  printf("%d %d %d %d %.6f\n", maior, menor, pares, impares, media);

  return 0;
}
