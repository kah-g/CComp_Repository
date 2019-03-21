#include <stdio.h>
#include <stdlib.h>

int main () {
  int a, b, rp;
  char op;
  scanf("%d %d %c", &a, &b, &op);
  switch (op) {
    case '+':
     rp = a + b;
     printf("RESP:%d\n", rp);
     break;
    case '-':
     rp = a - b;
     printf("RESP:%d\n", rp);
     break;
    case '*':
     rp = a * b;
     printf("RESP:%d\n", rp);
     break;
    case '/':
     rp = a / b;
     printf("RESP:%d\n", rp);
     break;
    default:
     printf("Invalido\n");
  }


  return 0;
}
