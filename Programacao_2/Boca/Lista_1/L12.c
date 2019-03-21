#include <stdio.h>
#include <stdlib.h>

int main () {
  int N1, N2, N3;
  scanf("%d %d %d", &N1, &N2, &N3);
  if ((N1 < N2) && (N1 < N3)) {
    if (N2 < N3) {
      printf("N1 = %d, N2 = %d, N3 = %d\n", N1, N2, N3);
    } else {
      printf("N1 = %d, N3 = %d, N2 = %d\n", N1, N3, N2);
    }
  } else if ((N2 < N1) && (N2 < N3)) {
    if (N1 < N3) {
      printf("N2 = %d, N1 = %d, N3 = %d\n", N2, N1, N3);
    } else {
      printf("N2 = %d, N3 = %d, N1 = %d\n", N2, N3, N1);
    }
  } else if (N1 < N2) {
    printf("N3 = %d, N1 = %d, N2 = %d\n", N3, N1, N2);
  } else {
    printf("N3 = %d, N2 = %d, N1 = %d\n", N3, N2, N1);
  }

  return 0;
}
