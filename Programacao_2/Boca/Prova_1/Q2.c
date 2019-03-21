#include <stdio.h>
#include <stdlib.h>

int main () {
  int a, b;
  scanf("%d %d", &a, &b);
  if ((a < 1) || (a > 10) || (b < 1) || (b > 10)) {
    printf("Invalido\n");
  } else if ((a >=1) && (a <=5)) {
    if (a == b) {
      printf("Um homem\n");
    } else if ((b >= 1) && (b <= 5)) {
      printf("Par de homens\n");
    } else if ((b >= 6) && (b <= 10)) {
      printf("Um casal\n");
    }
  } else if ((a >= 6) && (a <= 10)) {
    if (a == b) {
      printf("Uma mulher\n");
    } else if ((b >= 6) && (b <= 10)) {
      printf("Par de mulheres\n");
    } else if ((b >= 1) && (b <= 5)) {
      printf("Um casal\n");
    }
  }

  return 0;
}
