#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main () {
  int n,m,teste,c;
  scanf("%d %d", &n, &m);
  n += 1;
  while (n < m) {
  c = 2;
    while (c <= (n/2)) {
      teste = ((n%c) == 0);
      if (teste == TRUE) {
        break;
        //c vai dividindo n, e no caso de ser n ser true ele quebra o laço por não ser primo
      }
      c++;
    }
    if ((teste == FALSE) || (n == 2) || (n == 3)) {
      printf("%d\n", n);
      int c2,l=0;
      for(c2=2;(n*c2)<m;c2++) {
        printf("%d ", n*c2);
        l = TRUE;
        //l serve apenas para pular linha no caso de houver múltiplos
      }
      if (l == TRUE) {
        printf("\n");
      }
      if (c2 == 2) {
        printf("*\n");
      }
    }
    n++;
  }

  return 0;
}
