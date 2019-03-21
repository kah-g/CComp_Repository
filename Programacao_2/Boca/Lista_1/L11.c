#include <stdio.h>
#include <stdlib.h>

int main () {
  int mes;
  scanf("%d", &mes);
  switch (mes) {
    case 1:
     printf("Jan.\n");
     break;
    case 2:
     printf("Fev.\n");
     break;
    case 3:
     printf("Mar.\n");
     break;
    case 4:
     printf("Abr.\n");
     break;
    case 5:
     printf("Mai.\n");
     break;
    case 6:
     printf("Jun.\n");
     break;
    case 7:
     printf("Jul.\n");
     break;
    case 8:
     printf("Ago.\n");
     break;
    case 9:
     printf("Set.\n");
     break;
    case 10:
     printf("Out.\n");
     break;
    case 11:
     printf("Nov.\n");
     break;
    case 12:
     printf("Dez.\n");
     break;
    default:
     printf("Invalido.\n");
  }

  return 0;
}
