#include "jogo.h"

struct jogador {
  Baralho *mao;
  Baralho *monte;
  int pontuacao;
  int ia;//se for 0 e pĺayer, se for 1 e ia
};

struct celulajogador {
  Jogador *jog;
  CelulaJogador *prox;
};

struct players {
  CelulaJogador *prim;
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
    printf("Agora escolha a dificuldade:\n1-Facil.\n2-Dificil.\n3-Sair.\n");
    scanf("%d", &op2);
  }while (op2 < 1 && op2 > 3);
  if(op1 == 1 && op2 == 1) {
    IniciaJogo(1);
    //se modo de jogo e 1 e a dificuldade e 1, entao passa 1 como parametro de inicia jogo
  }
  if (op1 == 3) {
    exit(0);
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
  jogg->jog->ia = 0;
  return jogg;
}

CelulaJogador* InicializaJogadorIA () {
  CelulaJogador *jogg = (CelulaJogador*) malloc (sizeof(CelulaJogador));
  jogg->jog = (Jogador*) malloc (sizeof(Jogador));
  jogg->jog->mao = InicializaBaralhoVazio();
  jogg->jog->monte = InicializaBaralhoVazio();
  jogg->jog->pontuacao = 0;
  jogg->prox = NULL;
  jogg->jog->ia = 1;
  return jogg;
}

Players* InicializaJogo (int tipoJogo) {
  if(tipoJogo == 1) {
    //so inicia dois jogadores
    CelulaJogador *jogadorReal = InicializaJogador();
    CelulaJogador *jogadorIA = InicializaJogadorIA();
    Players *jogo01 = (Players*) malloc (sizeof(Players));
    //precisa de um metodo de selecionar quem comeca o jogo
    //essa parte tera que ser refeita
    jogo01->prim = jogadorReal;
    jogadorReal->prox = jogadorIA;
    jogadorIA->prox = jogo01->prim;
    jogo01->QttJogadores = 2;
    return jogo01;
  }
}

CelulaBaralho* JogadaReal (Jogador* jogg) {
  printf("Cartas na Mao:\n");
  PrintaBaralho(jogg->mao);
  int qut = VerificaBaralho(jogg->mao);
  if(qut < 3) {
    if(qut == 2) {
      int num;
      do {
        //colocar if < 1 || > 3 falar que num invalido
        printf("Escolha carta a ser jogada (1 ou 2).\n");
        scanf("%d", &num);
      } while (num < 1 || num > 2);
      CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
      switch (num) {
        case 1:
          aux = RetiraCartaGambiarra(aux,jogg->mao);
          return aux;
        case 2:
          aux = RetornaCartaUlt(jogg->mao);
          aux = RetiraCartaGambiarra(aux,jogg->mao);
          return aux;
      }
    } else {
      printf("Ultima carta jogada automaticamente\n");
      CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
      aux = RetiraCartaGambiarra(aux,jogg->mao);
      return aux;
    }
  } else {
    int num;
    do {
      //colocar if < 1 || > 3 falar que num invalido
      printf("\nEscolha carta a ser jogada (1 a 3).\n");
      scanf("%d", &num);
    } while (num < 1 || num > 3);
    CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
    switch (num) {
      case 1:
        aux = RetiraCartaGambiarra(aux,jogg->mao);;
        return aux;
      case 2:
        aux = RetornaCartaProx(aux);
        aux = RetiraCartaGambiarra(aux,jogg->mao);;
        return aux;
      case 3:
        aux = RetornaCartaUlt(jogg->mao);
        aux = RetiraCartaGambiarra(aux,jogg->mao);
        return aux;
    }
  }
}

CelulaBaralho* JogadaIA (Jogador* jogg) {
  int qut = VerificaBaralho(jogg->mao);
  if(qut < 3) {
    if(qut == 2) {
      srand(time(0));
      int num = rand()%2;
      CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
      switch (num) {
        case 0:
          aux = RetiraCartaGambiarra(aux,jogg->mao);
          return aux;
        case 1:
          aux = RetornaCartaUlt(jogg->mao);
          aux = RetiraCartaGambiarra(aux,jogg->mao);
          return aux;
      }
    } else {
      CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
      aux = RetiraCartaGambiarra(aux,jogg->mao);
      return aux;
    }
  } else {
    srand(time(0));
    int num = rand()%3;
    CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
    switch (num) {
      case 0:
        aux = RetiraCartaGambiarra(aux,jogg->mao);
        return aux;
      case 1:
        aux = RetornaCartaProx(aux);
        aux = RetiraCartaGambiarra(aux,jogg->mao);
        return aux;
      case 2:
        aux = RetornaCartaUlt(jogg->mao);
        aux = RetiraCartaGambiarra(aux,jogg->mao);
        return aux;
    }
  }
}


void IniciaJogo (int tipoJogo) {
  Baralho* brl = InicializaBaralho();
  brl = EmbaralharBaralho(brl);
  Carta* trunfo = CortaBaralho(brl);
  printf("\nTrunfo do Jogo:");
  PrintaCarta(trunfo);
  Players* jogadores = InicializaJogo(tipoJogo);
  DistribuiCartas(brl, jogadores);
  Baralho* mesa = InicializaBaralhoVazio();
  int rodadas=0;
  if(tipoJogo == 1) {
    rodadas = 40/2;
  }
  for(int l=0; l < rodadas; l++) {
    //int j=1;
    CelulaJogador *auxJ = jogadores->prim;
    for(int i=0; i < jogadores->QttJogadores; i++) {
      CelulaBaralho *aux;
      if(auxJ->jog->ia == 0) {
        aux = JogadaReal(auxJ->jog);
      } else {
        aux = JogadaIA(auxJ->jog);
      }
      InsereCarta(aux, mesa);
      auxJ = auxJ->prox;
    }
    printf("\nMesa:\n");
    PrintaBaralho(mesa);
    int gan = ComparaCartas(mesa, trunfo);
    //printar a ganhadora
    CelulaBaralho *CtGan = RetornaCartaPrim(mesa);
    CelulaJogador *JogGan = jogadores->prim;
    for(int i=0; i < gan; i++) {
      CtGan = RetornaCartaProx(CtGan);
      JogGan = JogGan->prox;
    }
    printf("\nGanhadora:");
    PrintaCelulaCarta(CtGan);
    //passa as cartas pro monte do jogador ganhador da rodada
    while(VerificaBaralho(mesa) > 0) {
      CelulaBaralho *ctRod = RetiraCartaTopo(mesa);
      InsereCarta(ctRod, JogGan->jog->monte);
    }
    //compra cartas aqui
    if(VerificaBaralho(brl) > 0) {
      CelulaJogador *JogComp = jogadores->prim;
      for(int i=0; i < jogadores->QttJogadores; i++) {
        CelulaBaralho *comp = RetiraCartaTopo(brl);
        InsereCarta(comp, JogComp->jog->mao);
        JogComp = JogComp->prox;
      }
    }
    printf("\nCartas no Baralho: %d\n", VerificaBaralho(brl));
    //j++;
  }
  printf("\n\nFim de Jogo\n");
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
