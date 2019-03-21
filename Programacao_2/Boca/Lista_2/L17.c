#include <stdio.h>
#include <stdlib.h>

int main () {
  int op1, op2;
  char texto, textoCod, textoDec;
  scanf("%d %d ", &op1, &op2);
  op2 = op2 % 26;
  switch (op1) {
    case 1:
     //codifica
     while (texto != '.') {
       scanf("%c", &texto);
       if ((texto >= 'a') && (texto <= 'z')) {
         if ((texto + op2) > 'z') {
           textoCod = 'a' + ((op2 - ('z' - texto)) - 1);
           printf("%c", textoCod);
         } else {
           textoCod = texto + op2;
           printf("%c", textoCod);
         }
         //printf("%c", textoCod);
       } else {
         textoCod = texto;
         printf("%c", textoCod);
       }
       //printf("%c\n", textoCod);
     }
     printf("\n");
     break;
    case 2:
     //decodifica
     while (texto != '.') {
       scanf("%c", &texto);
       if ((texto >= 'a') && (texto <= 'z')) {
         if ((texto - op2) < 'a') {
           textoDec = 'z' - ((op2 - ('a' - texto)) - 1);
           printf("%c", textoDec);
         } else {
           textoDec = texto - op2;
           printf("%c", textoDec);
         }
       } else {
         textoDec = texto;
         printf("%c", textoDec);
       }
     }
     printf("\n");
     break;
    default:
     printf("Operacao Invalida\n");
  }

  return 0;
}
