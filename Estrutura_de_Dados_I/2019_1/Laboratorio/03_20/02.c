#include <stdio.h>
#include <stdlib.h>

int main () {
  int num1, num2;
  printf("Entre com dois numeros inteiros:\n");
  scanf("%d %d", &num1, &num2);
  if (&num1 >= &num2) {
    printf("%p\n", &num1);
  } else {
    printf("%p\n", &num2);
  }
  return 0;
}
