#include <stdio.h>
#include <stdlib.h>

int main () {
  char letra;
  scanf("%c", &letra);
  if (letra == 'a'|| letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U') {
    printf("Vogal\n");
  }
  else {
    printf("Nao Vogal\n");
  }

  return 0;
}
