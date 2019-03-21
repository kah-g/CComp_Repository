#include <stdio.h>
#include <stdlib.h>

int main () {
  char letra;
  while ((letra != '.') && (letra != '?') && (letra != '!')) {
    scanf("%c", &letra);
    if ((letra >= 'a') && (letra <= 'z')) {
      letra = letra - 32;
    }
    printf("%c", letra);
  }
  //printf("\n");

  return 0;
}
