#include <stdio.h>
#include <stdlib.h>

int main () {
  int n,m,ab,cd,ef,ef2;
  scanf("%d %d", &n, &m);
  for (n++;n<m;n++) {
    //dessa forma ele vai calcular todos os numeros pra ver os que se encaixam no if
    //printf("n: %d\n", n);
    ab = n / 100;
    //printf("ab: %d\n", ab);
    cd = n - (ab * 100);
    //printf("cd: %d\n", cd);
    ef = ab + cd;
    //printf("ef: %d\n", ef);
    ef2 = ef * ef;
    //printf("ef ao quadrado: %d\n", ef2);
    if (ef2 == n) {
      printf("%d\n", n);
    }
  }

  return 0;
}
