#include <stdio.h>
#include <stdlib.h>

int main () {
  int h1, m1, s1, h2, m2, s2, soma1, soma2, soD1, soD11, soD2, soD22;
  scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
  soma1 = h1 + m1 + s1;
  soma2 = h2 + m2 + s2;
  soD1 = soma1 / 10;
  soD11 = soD1 - 10;
  soD2 = soma2 / 10;
  soD22 = soD2 - 10;
  if (((h1 == h2) && (m1 == m2) && (s1 == s2))||(soma1 == soma2)) {
    printf("IGUAIS\n");
  } else if (h1 == h2) {
    if (m1 == m2) {
      if (s1 > s2) {
        if (soma1 < 10) {
            printf("RESP:0\n");
          } else if (soD1 < 10) {
            printf("RESP:%d\n", soD1);
          } else {
            printf("RESP:%d\n", soD11);
        }
      } else {
        if (soma2 < 10) {
          printf("RESP:0\n");
        } else if (soD2 < 10) {
          printf("RESP:%d\n", soD2);
        } else {
          printf("RESP:%d\n", soD22);
        }
      }
    } else if (m1 > m2) {
      if (soma1 < 10) {
          printf("RESP:0\n");
        } else if (soD1 < 10) {
          printf("RESP:%d\n", soD1);
        } else {
          printf("RESP:%d\n", soD11);
      }
    } else {
      if (soma2 < 10) {
        printf("RESP:0\n");
      } else if (soD2 < 10) {
        printf("RESP:%d\n", soD2);
      } else {
        printf("RESP:%d\n", soD22);
      }
    }
  } else if (h1 > h2) {
    if (soma1 < 10) {
        printf("RESP:0\n");
      } else if (soD1 < 10) {
        printf("RESP:%d\n", soD1);
      } else {
        printf("RESP:%d\n", soD11);
    }
  } else {
    if (soma2 < 10) {
      printf("RESP:0\n");
    } else if (soD2 < 10) {
      printf("RESP:%d\n", soD2);
    } else {
      printf("RESP:%d\n", soD22);
    }
  }

  return 0;
}
