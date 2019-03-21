#include <stdio.h>
#include <stdlib.h>

//aprendendo a usar arrays
//para um array de 5 elemento, definir o maior elemento

int main () {
  int nums[5];
  int i, maior=-9999;
  printf("Entre com os 5 elementos\n");
  for (i = 0; i < 5; i++) {
    scanf("%d", &nums[i]);
  }
  for (i=0; i < 5; i++) {
    if (nums[i] > maior) {
      maior = nums[i];
    }
  }
  printf("O maior numero e: %d\n", maior);

  return 0;
}
