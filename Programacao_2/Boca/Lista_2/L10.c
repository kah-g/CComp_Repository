#include <stdio.h>
#include <stdlib.h>

int main () {
  int n,m,multi;
  scanf("%d %d", &n, &m);
  for (;n<=m;n++) {
    for (multi=1;multi<=10;multi++) {
      printf("%d x %d = %d\n", n, multi, n*multi);
    }
  }

  return 0;
}
