#include <stdio.h>
#include <stdlib.h>

int main () {
  int n=1, maior=-9999,c=0;
  float media=0;
  while (n != 0) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    if (n > maior) {
      maior = n;
    }
    media += n;
    c++;

    printf("%d %.6f\n", maior, media/c);
  }

  return 0;
}
