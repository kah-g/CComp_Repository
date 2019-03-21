#include <stdio.h>
#include <stdlib.h>

int main () {
  int q,n,c1,c2=0,c3=9999;
  scanf("%d", &q);
  if (q <= 0) {
    return 0;
  }
  for (c1=1; c1 <= q; c1++) {
    scanf("%d", &n);
    if (n < c3) {
      c3 = n;
      c2 = c1;
    }
  }
  printf("POS:%d\n", c2);
  return 0;
}
