#include <stdio.h>
#include <stdlib.h>

int main () {
  int N1, N2;
  scanf("%d %d", &N1, &N2);
  if (N1 > N2) {
    printf("N1 = %d\n", N1);
  }
  else if (N2 > N1) {
    printf("N2 = %d\n", N2);
  }
  else {
    printf("N1 = N2\n");
  }

  return 0;
}
