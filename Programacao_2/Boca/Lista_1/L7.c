#include <stdio.h>
#include <stdlib.h>

int main () {
  float temp, conv;
  char tm;
  scanf("%f %c", &temp, &tm);
  //tm = getchar();
  if (tm == 'c' || tm == 'C') {
    conv = (temp * (9.0/5.0)) + 32;
    printf("%.2f (F)\n", conv);
  }
  else if (tm == 'f' || tm == 'F') {
    conv = 5.0 * ((temp - 32)/9.0);
    printf("%.2f (C)\n", conv);
  }

  return 0;
}
