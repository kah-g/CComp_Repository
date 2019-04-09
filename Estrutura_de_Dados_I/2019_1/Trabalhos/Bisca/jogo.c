#include "jogo.h"

void Menu () {
  //menu de inciar a o jogo
  printf("---------- Bem vindo a Bisca Virtual!!!! ----------\n\n");
  int op1 = 0, op2 = 0;
  do {
    printf("Escolha um modo de jogo:\n1-Jogo com 2 players.\n2-Jogo com 4 players.\n3-Sair\n");
    scanf("%d", &op1);
  }while (op1 < 1 && op1 > 3);
  if (op1 == 3) {
    exit(0);
  }
  do {
    printf("Agora escolha a dificuldade:\n1-Facil.\n2-Dificil.\n3-Voltar.\n");
    scanf("%d", &op2);
  }while (op2 < 1 && op2 > 3);
  if(op1 == 1 && op2 == 1) {
    IniciaJogo1();
  } else {
    printf("Opa, essas opcoes ainda nao estao prontas. Sorryyyy!\n\n");
    exit(0);
  }
}

void IniciaJogo1 () {
  Baralho* brl = InicializaBaralho();
  brl = EmbaralharBaralho(brl);
  Carta* trunfo = CortaBaralho(brl);
  printf("\nTrunfo do Jogo:");
  PrintaCarta(trunfo);
  //distribuir cartas
  Baralho *mao = InicializaMaoVazia();
  Baralho *maoIA = InicializaMaoVaziaIA();

}
