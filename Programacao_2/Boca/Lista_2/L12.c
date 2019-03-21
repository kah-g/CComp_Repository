#include <stdio.h>
#include <stdlib.h>

int main () {
  char letra;
  int c=0;
  while ((letra != '.') && (letra != '?') && (letra != '!')) {
    scanf("%c", &letra);
    if (letra == ' ') {
      letra = '_';
    }
    if (c == 0) {
      printf("RESP:");
    }
    c += 1;
    printf("%c", letra);
  }
  printf("\n");

  return 0;
}
