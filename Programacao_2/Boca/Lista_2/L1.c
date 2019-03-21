#include <stdio.h>
#include <stdlib.h>

int main () {
  int n,m,c;
  scanf("%d %d", &n, &m);
  c = n;
  if (!((c%2) != 0)) {
    printf("RESP:");
    c += 2;
    while (c<m) {
      printf("%d ", c);
      c += 2;
    }
  } else {
    c += 1;
    printf("RESP:");
    while (c<m) {
      printf("%d ", c);
      c += 2;
    }
  }
  printf("\n");

  return 0;
}
