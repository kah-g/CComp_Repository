#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int InverteNumero (int num);

int Tamanho (int num);

int EhIgual (int num);

int InverteNumero2(int);

int main () {
  int num, cont=0;
  while (scanf("%d", &num) == 1) {
    //printf("%d\n", num);
    if (EhIgual (num)) {
      cont++;
    }
  }
  //printf("%d\n", cont);
  printf("COUNT: %d\n", cont);

  return 0;
}

int InverteNumero (int num) {
  int cont,numI=0,r,cont2;
  cont = Tamanho (num);
  for (;cont > 0; cont--) {
    cont2 = cont;
    r = num % 10;
    for (;cont2 > 0; cont2--) {
      r = r*10;
    }
    numI += r;
    num /= 10;
  }
  if (cont == 0) {
    numI += num;
  }

  //printf("%d\n",numI);

  return numI;
}


int Tamanho (int num) {
  int cont=1;
  while ((num / 10) > 9) {
    cont++;
    num /= 10;
  }

  return cont;
}

int EhIgual (int num) {
  int numI;
  if (num > 9) {
      numI = InverteNumero (num);
      // printf("%d - %d\n",num,numI);
      if (num == numI) {
        return 1;
      } else {
        return 0;
      }
  } else {
    return 1;
  }
}
