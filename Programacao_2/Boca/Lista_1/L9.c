#include <stdio.h>
#include <stdlib.h>

int main () {
  char letra, letraN;
  scanf("%c", &letra);
  if (letra >=  97 && letra <= 122) {
    letraN = letra - 32;
    printf("%c(%d)\n", letraN, letraN);
  }
  else if (letra >= 65 && letra <= 90) {
    printf("A letra deve ser minuscula!\n");
  }
  else {
    printf("Nao e letra!\n");
  }

  return 0;
}
