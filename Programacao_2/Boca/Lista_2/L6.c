#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
  int s;
  scanf("%d", &s);
  if (s == 1) {
    //int a=3,b=2;
    double divi=0, soma=1.0, a=3.0, b=2.0;
    while ((a <= 99) && (b <= 50)) {
      divi = a/b;
      soma += divi;
      //printf("%lf %lf\n", a, b);
      a += 2;
      b++;
    }
    printf("%.6lf\n", soma);
  } else if (s == 2) {
    double divi=0, soma=0, a=1.0, b=50.0, c=0;
    while ((a <= 50) && (a >= 0)) {
      c = pow (2.0,a);
      divi = c/b;
      soma += divi;
      a++;
      b--;
    }
    printf("%.6lf\n", soma);
  } else if (s == 3) {
    double divi=0, soma=1, a=2;
    while (a <= 10) {
      divi = a/(a*a);
      soma += divi;
      a++;
    }
    printf("%.6lf\n", soma);
  }

  return 0;
}
