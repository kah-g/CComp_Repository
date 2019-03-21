#include <stdio.h>
#include <stdlib.h>

#include "func.h"

int main () {

double a, b;
int opcao;
do{
  menu ();
  scanf("%d", &opcao);
  if ((opcao > 0) && (opcao < 5) ) {
    printf("Informe os Valores\n");
    scanf("%lf %lf", &a, &b);
  }
  switch (opcao) {
    case 1:
     printf("Soma: %lf\n", soma(a,b));
     break;
    case 2:
     printf("Subtrai: %lf\n", subtrai(a,b));
     break;
    case 3:
     printf("Multiplica: %lf\n", multiplica(a,b));
     break;
    case 4:
     printf("Divisao: %lf\n", divide(a,b));
     break;
    default:
     break;
  }
} while (opcao != 5);

return 0;
}
