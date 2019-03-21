#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int QtdDebitoPlaca (int anosC, int anosPlaca, int valorPlaca);
int ConverteNumero (char num);

int main () {
  int quantC, anosC, i, t;
  char placa[30];
  scanf("%d", &quantC);
  for (i=0; i < quantC; i++) {
    scanf("%d", &anosC);
    while (1) {
      fgets (placa, 30, stdin);
      if (placa == "FIM") {
        break;
      }
      t = strlen (placa);
    }
  }

  return 0;
}

int QtdDebitoPlaca (int anosC, int anosPlaca, int valorPlaca) {

}

int ConverteNumero (char num) {
  switch (num) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
  }
}
