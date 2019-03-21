#include <stdio.h>
#include<stdlib.h>

int main () {
  int lin,col, i, j, num, maior=-9999, linS=0, colS=0;
  scanf("%d %d", &lin, &col);
  for (i=1;i <= lin; i++) {
    for (j=1; j <= col; j++) {
      scanf("%d", &num);
      if (num > maior) {
        maior = num;
        linS = i;
        colS = j;
      }
    }
  }
  printf("%d (%d, %d)\n", maior, linS, colS);

  return 0;
}
