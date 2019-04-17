#include "jogo.h"

struct jogador {
  Baralho *mao;
  Baralho *monte;
  int pontuacao;
};

struct celulajogador {
  Jogador *jog;
  CelulaJogador *prox;
};

struct players {
  CelulaJogador *prim;
  CelulaJogador *ult;
  int QttJogadores;
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
    IniciaJogo(1);
    //se modo de jogo e 1 e a dificuldade e 1, entao passa 1 como parametro de inicia jogo
  } else {
    printf("Opa, essas opcoes ainda nao estao prontas. Sorryyyy!\n\n");
    exit(0);
  }
}

CelulaJogador* InicializaJogador () {
  CelulaJogador *jogg = (CelulaJogador*) malloc (sizeof(CelulaJogador));
  jogg->jog = (Jogador*) malloc (sizeof(Jogador));
  jogg->jog->mao = InicializaBaralhoVazio();
  jogg->jog->monte = InicializaBaralhoVazio();
  jogg->jog->pontuacao = 0;
  jogg->prox = NULL;
  return jogg;
}
Players* InicializaJogo (int tipoJogo) {
  if(tipoJogo == 1) {
    //so inicia dois jogadores
    CelulaJogador *jogadorReal = InicializaJogador();
    CelulaJogador *jogadorIA = InicializaJogador();
    Players *jogo01 = (Players*) malloc (sizeof(Players));
    //precisa de um metodo de selecionar quem comeca o jogo
    //essa parte tera que ser refeita
    jogo01->prim = jogadorReal;
    jogadorReal->prox = jogadorIA;
    jogo01->ult = jogadorIA;
    jogadorIA->prox = NULL;
    jogo01->QttJogadores = 2;
    return jogo01;
  }
}

CelulaBaralho* JogadaReal (Jogador* jogg) {
  printf("Baralhos na Mao:\n");
  PrintaBaralho(jogg->mao);
}


void IniciaJogo (int tipoJogo) {
  Baralho* brl = InicializaBaralho();
  brl = EmbaralharBaralho(brl);
  Carta* trunfo = CortaBaralho(brl);
  printf("\nTrunfo do Jogo:");
  PrintaCarta(trunfo);
  Players* jogadores = InicializaJogo(tipoJogo);
  DistribuiCartas(brl, jogadores);
}


void DistribuiCartas (Baralho *brl, Players *jogadores) {
  for (int i=0; i < 3; i++) {
    CelulaJogador *auxJ = jogadores->prim;
    for(int j=0; j < jogadores->QttJogadores; j++) {
      CelulaBaralho *aux = RetiraCartaTopo(brl);
      InsereCarta(aux, auxJ->jog->mao);
      auxJ = auxJ->prox;
    }
  }
}
