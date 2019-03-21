#include <stdio.h>
#include <stdlib.h>

int main () {
  int num, ordem;
  scanf("%d %d", &num, &ordem);
  switch (ordem) {
    case 1:
     if ((num % 2) == 0) {
       printf("PAR\n");
     } else {
       printf("IMPAR\n");
     }
     break;
    case 2:
     num = num / 10;
     if ((num % 2) == 0) {
       printf("PAR\n");
     } else {
       printf("IMPAR\n");
     }
     break;
    case 3:
     num = num / 100;
     if ((num % 2) == 0) {
       printf("PAR\n");
     } else {
       printf("IMPAR\n");
     }
     break;
  }

  return 0;
}
