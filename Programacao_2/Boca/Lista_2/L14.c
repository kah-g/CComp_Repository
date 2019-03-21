#include <stdio.h>
#include <stdlib.h>

int main () {
  char letra;
  int c=0;
  while ((letra != '.') && (letra != '?') && (letra != '!')) {
    scanf("%c", &letra);
    if (c == 0) {
      printf("RESP:");
    }
    c += 1;
    if (letra != ' ') {
      printf("%c", letra);
    }
    //printf("%c", letra);
  }
  printf("\n");

  return 0;
}
