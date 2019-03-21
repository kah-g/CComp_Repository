#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main () {
  int n,teste,c=2;
  scanf("%d", &n);
  while (c <= (n/2)) {
    teste = ((n%c) == 0);
    if (teste == TRUE) {
      break;
    }
      c++;
  }
  if ((teste == 0) || (n == 2) || (n == 3)) {
    printf("Primo\n");
  } else {
    printf("Nao primo\n");
  }

  return 0;
}
