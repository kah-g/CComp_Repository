#include <stdio.h>
#include <stdlib.h>

int main () {
  float n1, n2, me;
  scanf("%f %f", &n1, &n2);
  me = (n1 + n2)/2;
  if (me < 5) {
    printf("%.1f - Reprovado\n", me);
  }
  else if (me >= 7) {
    printf("%.1f - Aprovado\n", me);
  }
  else {
    printf("%.1f - De Recuperacao\n", me);
  }

  return 0;
}
