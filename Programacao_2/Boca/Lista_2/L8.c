#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main () {
  int n,m,teste,c;
  scanf("%d %d", &n, &m);
  n += 1;
  printf("RESP:");
  while (n < m) {
  c = 2;
    while (c <= (n/2)) {
      teste = ((n%c) == 0);
      //printf("%d\n", teste);
      if (teste == TRUE) {
        break;
      }
      c++;
    }
    if ((teste == FALSE) || (n == 2) || (n == 3)) {
      printf("%d ", n);
    }
    n++;
  }
  printf("\n");

  return 0;
}
