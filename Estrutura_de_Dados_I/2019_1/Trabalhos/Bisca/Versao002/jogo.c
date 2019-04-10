#include "jogo.h"

struct jogador {
  Baralho *mao;
  Baralho *monte;
  int pontuacao;
};

struct celularjogador {
  Jogador *jog;
  celularjogador *prox;
};

struct players {
  Jogador *prim;
  Jogador *ult;
};

void Menu () {
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
    InicializaJogo01();
  } else {
    printf("Opa, essas opcoes ainda nao estao prontas. Sorryyyy!\n\n");
    exit(0);
  }
}

CelulaJogador* InicializaJogador () {
  CelulaJogador *jog01 = (CelulaJogador*) malloc (sizeof(CelulaJogador));
  jog01->jog = (Jogador*) malloc (sizeof(Jogador));
  jog01->jog->mao = InicializaBaralhoVazio();
  jog01->jog->monte = InicializaBaralhoVazio();
  jog01->jog->pontuacao = 0;
  jog01->prox = NULL;
  return jog01;
}
Players* InicializaJogo01 () {
  //so inicia dois jogadores
  CelulaJogador *jogg01 = InicializaJogador();
  CelulaJogador *jogIA = InicializaJogador();
  Players *jogo01 = (Players*) malloc (sizeof(Players));
  printf("Jogador, escolha impar ou par, pra decidir quem começa o jogo.\n");
}

void IniciaJogo () {
  Baralho* brl = InicializaBaralho();
  brl = EmbaralharBaralho(brl);
  Carta* trunfo = CortaBaralho(brl);
  printf("\nTrunfo do Jogo:");
  PrintaCarta(trunfo);
  //inicializamao
  Baralho *mao = InicializaMaoVazia();
  Baralho *maoIA = InicializaMaoVazia();
  //verificarmaos
  if (VerificaBaralho(mao) != 0 || VerificaBaralho(maoIA) != 0) {
    printf("ERRO: Problema na inicializao daos maos.\n");
    exit(1);
  }
  DistribuiCartas(brl, mao, maoIA);
}

/*Baralho* InicializaMaoVazia () {
  //mao e do tipo baralho pois possui a mesma estrutura
  Baralho *mao = InicializaBaralhoVazio();
  return mao;
}*/

void DistribuiCartas (Baralho *brl, Baralho *mao, Baralho *maoIA) {
  for (int i=0; i < 3; i++) {
    CelulaBaralho *aux = RetiraCartaTopo(brl);
    InsereCarta(aux, mao);
    aux = RetiraCartaTopo(brl);
    InsereCarta(aux, maoIA);
  }
  PrintaBaralho(mao);
  //PrintaBaralho(maoIA);
  //PrintaBaralho(brl);
}
