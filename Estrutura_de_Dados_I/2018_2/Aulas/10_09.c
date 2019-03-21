#include <stdio.h>
#include <stdlib.h>

int recursao(int maior, int menor);

int main () {
  //recursao mdc
  int p, q, r;
  printf("Entre com o valor de p: ");
  scanf("%d", &p);
  printf("Entre com o valor de q: ");
  scanf("%d", &q);

  if(p>q) {
    r = recursao(p,q);
  } else {
    r = recursao(q,p);
  }

  printf("Resultado: %d\n", r);
}

int recursao(int maior, int menor) {
  if(menor == 0) {
    return maior;
  }
  recursao(menor, maior%menor);
}
