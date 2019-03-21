#include <stdio.h>
#include <stdlib.h>

int main () {
  int n1,n2,n3,n4;
  float m;
  printf("Entre com as notas \n");
  scanf("%d", &n1);
  scanf("%d", &n2);
  scanf("%d", &n3);
  scanf("%d", &n4);
  m = (n1+n2+n3+n4)/4;
  printf("A media é: %.1f\n", m);

  return 0;
}
