#include "abb.h"
#include <time.h>

int main () {
  //a ideia do testador e preencher a arvore com numeros randomicos
  //depois pedir ao usuario para escolher alguns numeros para buscar na CriaArvoreVazia
  //depois imprimir a arvore e libera-la
  printf("Let's Play...\n");
  srand(time(0));
  Tree* A = CriaArvoreVazia();
  int y = rand() %100;
  A = Insere(A, y);
  printf("A arvore sera preenchida com numeros aleatorios de 0 a 100.\n");
  Tree* B = CriaArvoreVazia();
  for(int i=0; i < 43; i++) {
    int x = rand() %100;
    B = Insere(A, x);
  }
  printf("Vamos buscar e retirar um numero da arvore, caso ele exista.\n");
  int z;
  Tree* W;
  for(int i = 0; i < 5; i++) {
    printf("Digite um numero de 0 a 100... ");
    scanf("%d", &z);
    W = Busca(A, z);
    if(W != NULL) {
      printf("Bingo!!! Voce acertou.\n");
      Retira(A, z);
    } else {
      printf("Buh!! Esse numero nao esta na arvore.\n");
    }
  }
  ImprimeCrescente(A);
  Libera(A);

  return 0;
}
