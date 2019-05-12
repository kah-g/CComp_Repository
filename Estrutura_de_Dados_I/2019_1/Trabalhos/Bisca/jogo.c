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
  printf("################ Bem vindo a Bisca Virtual!!!! ################\n\n");
  int op1 = 0, op2 = 0;
  do {
    printf("Escolha um modo de jogo:\n1-Jogo com 2 players.\n2-Jogo com 4 players.\n3-Modo Debug(teste).\n4-Sair\n");
    scanf("%d", &op1);
  }while (op1 < 1 || op1 > 4);
  if(op1 == 4) {
    exit(0);
  }
  if(op1 == 3) {
    Debug ();
    exit(0);
  }
  do {
    printf("\nAgora escolha a dificuldade:\n1-Facil.\n2-Dificil.\n3-Sair.\n");
    scanf("%d", &op2);
  }while (op2 < 1 || op2 > 3);
  if(op1 == 1 && op2 == 1) {
    IniciaJogo(1);
    //se modo de jogo e 1 e a dificuldade e 1, entao passa 1 como parametro de inicia jogo
  }
  if(op1 == 2 && op2 == 1) {
    IniciaJogo(2);
    //se modo de jogo e 2 e a dificuldade e 1, entao passa 2 como parametro
  }
  if(op1 == 1 && op2 == 2) {
    //se modo de jogo e 1 e a dificuldade e 2, entao passa 3 como parametro
    IniciaJogo(3);
  }
  if(op1 == 2 && op2 == 2) {
    //se modo de jogo e 2 e a dificuldade e 2, entao passa 4 como parametro
    IniciaJogo(4);
  }
  if(op1 == 3) {
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

int InicializaJogo (int tipoJogo, Players *jogadores, int* posP) {
  if(tipoJogo == 1 || tipoJogo == 3) {
    //inicia dois jogadores
    CelulaJogador *jogadorReal = InicializaJogador(); //sempre e o numero 0
    CelulaJogador *jogadorIA = InicializaJogadorIA(); //numero 1
    srand(time(0));
    int aleatorio = rand()%2; //sorteando quem comeca o jogo
    int PontoCorte = 0;
    if(aleatorio == 0) {
      do {
        printf("\nEscolha onde cortar o baralho, entre 1 e 40.\n");
        scanf("%d", &PontoCorte);
      } while ((PontoCorte < 1) && (PontoCorte > 40));
      PontoCorte--;
      jogadores->prim = jogadorReal;
      printf("Voce eh o jogador: 1.\n");
      *posP = 1;
    } else {
      PontoCorte = rand()%40;
      printf("\nJogador IA 1 cortou o baralho em: %d\n", PontoCorte);
      jogadores->prim = jogadorIA;
      printf("Voce eh o jogador: 2.\n");
      *posP = 2;
    }
    jogadorReal->prox = jogadorIA;
    jogadorIA->prox = jogadorReal;
    jogadores->QttJogadores = 2;
    return PontoCorte;
  }
  if(tipoJogo == 2 || tipoJogo == 4) {
    //inicia 4 jogadores
    CelulaJogador *jogadorReal = InicializaJogador(); //sempre e o numero 0
    CelulaJogador *jogadorIA1 = InicializaJogadorIA(); //numero 1
    CelulaJogador *jogadorIA2 = InicializaJogadorIA(); //numero 2
    CelulaJogador *jogadorIA3 = InicializaJogadorIA(); //numero 3
    srand(time(0));
    int aleatorio = rand()%4; //sorteando quem comeca o jogo
    int PontoCorte = 0;
    if(aleatorio == 0) {
      do {
        printf("\nEscolha onde cortar o baralho, entre 1 e 40.\n");
        scanf("%d", &PontoCorte);
      } while ((PontoCorte < 1) || (PontoCorte > 40));
      PontoCorte--;
      jogadores->prim = jogadorReal;
    } else {
      if(aleatorio == 1) {
        jogadores->prim = jogadorIA1;
      }
      if(aleatorio == 2) {
        jogadores->prim = jogadorIA2;
      }
      if(aleatorio == 3) {
        jogadores->prim = jogadorIA3;
      }
      PontoCorte = rand()%40;
      printf("\nJogador IA %d cortou o baralho em: %d\n", aleatorio, PontoCorte);
    }
    jogadorReal->prox = jogadorIA1;
    jogadorIA1->prox = jogadorIA2;
    jogadorIA2->prox = jogadorIA3;
    jogadorIA3->prox = jogadorReal;
    jogadores->QttJogadores = 4;
    CelulaJogador *aux = jogadores->prim;
    for(int l=0; l < jogadores->QttJogadores; l++) {
      if(aux->jog->ia == 0) {
        printf("Voce eh o jogador: %d.\n", l+1);
        *posP = l+1;
      }
      aux = aux->prox;
    }
    return PontoCorte;
  }
}

CelulaBaralho* JogadaReal (Jogador* jogg) {
  printf("+++++++++++ Sua vez +++++++++++\n");
  printf("\nCartas na Mao:\n");
  PrintaBaralhoNumerado(jogg->mao);
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
      printf("\nUltima carta jogada automaticamente\n");
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

void LimparPlayers (Players *jogadores) {
  CelulaJogador *aux = jogadores->prim;
  if(aux == NULL || jogadores->QttJogadores == 0) {
    free(jogadores);
  } else {
    if(jogadores->QttJogadores > 1) {
      CelulaJogador *aux2;
      for(int i=0; i < jogadores->QttJogadores; i++) {
        aux2 = aux;
        aux = aux->prox;
        LimparBaralhos(aux2->jog->mao);
        LimparBaralhos(aux2->jog->monte);
        free(aux2->jog);
        free(aux2);
      }
      free(jogadores);
    } else {
      if(jogadores->QttJogadores == 1) {
        LimparBaralhos(aux->jog->mao);
        LimparBaralhos(aux->jog->monte);
        free(aux->jog);
        free(aux);
        free(jogadores);
      }
    }
  }
}

CelulaBaralho* JogadaIAD (Jogador* jogg, Carta* trunfo) {
  int qut = VerificaBaralho(jogg->mao);
  int ct;
  if(qut == 3) {
    ct = ComparaCartasIa(jogg->mao, trunfo);
    CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
    switch (ct) {
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
  if(qut == 2) {
    ct = ComparaCartasIa(jogg->mao, trunfo);
    CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
    switch (ct) {
      case 0:
        aux = RetiraCartaGambiarra(aux,jogg->mao);
        return aux;
      case 1:
        aux = RetornaCartaUlt(jogg->mao);
        aux = RetiraCartaGambiarra(aux,jogg->mao);
        return aux;
    }
  }
  if(qut == 1) {
    CelulaBaralho *aux = RetornaCartaPrim(jogg->mao);
    aux = RetiraCartaGambiarra(aux,jogg->mao);
    return aux;
  }
}

void IniciaJogo (int tipoJogo) {
  Baralho* brl = InicializaBaralho();
  brl = EmbaralharBaralho(brl);
  Players *jogadores = (Players*) malloc (sizeof(Players));
  int posP = 0;
  int PontoCorte = InicializaJogo(tipoJogo, jogadores, &posP);
  Carta* trunfo = CortaBaralho(brl, PontoCorte);
  /*printf("\nTrunfo do Jogo:");
  PrintaCarta(trunfo);*/
  DistribuiCartas(brl, jogadores);
  Baralho* mesa = InicializaBaralhoVazio();
  int rodadas=0;
  if(tipoJogo == 1 || tipoJogo == 3) {
    rodadas = 40/2;
  }
  if(tipoJogo == 2 || tipoJogo == 4) {
    rodadas = 40/4;
  }
  for(int l=0; l < rodadas; l++) {
    printf("---------------- Rodada %d de %d. ---------------- \n", l+1, rodadas);
    printf("\nTrunfo do Jogo: ");
    PrintaCarta(trunfo);
    CelulaJogador *auxJ = jogadores->prim;
    for(int i=0; i < jogadores->QttJogadores; i++) {
      CelulaBaralho *aux;
      if(auxJ->jog->ia == 0) {
        aux = JogadaReal(auxJ->jog);
      } else {
        printf("+++++++++++ Vez do Jogador %d (IA). +++++++++++\n", i+1);
        if(tipoJogo == 1 || tipoJogo == 2) {
          aux = JogadaIA(auxJ->jog);
        }
        if(tipoJogo == 3 || tipoJogo == 4) {
          aux = JogadaIAD(auxJ->jog, trunfo);
        }
      }
      printf("Carta Jogada: ");
      PrintaCelulaCarta(aux);
      InsereCarta(aux, mesa);
      auxJ = auxJ->prox;
      printf("Mesa:\n");
      PrintaBaralho(mesa);
    }
    int gan = ComparaCartas(mesa, trunfo);
    //printar a ganhadora
    CelulaBaralho *CtGan = RetornaCartaPrim(mesa);
    CelulaJogador *JogGan = jogadores->prim;
    for(int i=0; i < gan; i++) {
      CtGan = RetornaCartaProx(CtGan);
      JogGan = JogGan->prox;
    }
    printf("Jogador %d ganhou a rodada com a carta: ", gan+1);
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
    //printf("\nCartas no Baralho: %d\n", VerificaBaralho(brl));
    printf("---------------- Fim da Rodada %d. ---------------- \n", l+1);
  }
  //hora de contar os pontos
  CelulaJogador *JogP = jogadores->prim;
  int MaxPontos = 0, Gan;
  for(int i=0; i < jogadores->QttJogadores; i++) {
    JogP->jog->pontuacao = ContagemPontos(JogP->jog->monte);
    printf("Pontuacao de jogador %d: %d.\n", i+1, JogP->jog->pontuacao);
    if(JogP->jog->pontuacao > MaxPontos) {
      Gan = i;
      MaxPontos = JogP->jog->pontuacao;
    }
    JogP = JogP->prox;
  }
  if(Gan+1 == posP) {
    printf("\nVoce ganhou!! Pontuacao total: %d.\n", MaxPontos);
  } else {
    printf("\nVoce perdeu! Jogador %d (IA) ganhou. Pontuacao total: %d\n", Gan+1, MaxPontos);
  }
  LimparPlayers(jogadores);
  LimparBaralhos(mesa);
  LimparBaralhos(brl);
  printf("\n################ Fim de Jogo. ################\n");
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

void Debug () {
  printf("---------------- Modo Debug ----------------\n");
  printf("Vamos começar criando um baralho.\n");
  Baralho* debug = InicializaBaralho();
  printf("Baralho criado.\n");
  PrintaBaralho(debug);
  int op=0;
  do {
    printf("Escolha uma das opcoes:\n1-Embaralhar o Baralho.\n2-Cortar o Baralho.\n3-Retirar Carta.\n4-Sair.\n");
    scanf("%d", &op);
    if(op == 1 || op == 2 || op == 3) {
      if(VerificaBaralho(debug) > 1) {
        if(op == 1) {
          debug = EmbaralharBaralho(debug);
          PrintaBaralho(debug);
        }
        if(op == 2) {
          int pontoC = 0;
          do {
            printf("Escolha onde cortar o baralho.\n");
            scanf("%d", &pontoC);
          }while (pontoC < 1 || pontoC>VerificaBaralho(debug));
          Carta* cortada = CortaBaralho(debug, pontoC);
          printf("Carta cortada:\n");
          PrintaCarta(cortada);
          printf("Baralho apos o corte:\n");
          PrintaBaralho(debug);
        }
        if(op == 3) {
          int naipe, valor;
          do {
            printf("Escolha o naipe da carta a ser retirada:\n1-Ouro.\n2-Espadas.\n3-Copas.\n4-Paus.\n");
            scanf("%d", &naipe);
            //naipe--;
          }while(naipe <0 || naipe >4);
          do{
            printf("Escolha o valor da carta a ser retirada:\n1-AS.\n11-Valete.\n12-Rainha.\n13-Rei.\n");
            scanf("%d", &valor);
            if(valor == 1) {
              valor = 14;
            }
          }while((valor <2 || valor >14) || (valor>= 8 && valor <=10));
          CelulaBaralho* cb2;
          CelulaBaralho* cbR;
          cbR = CriaCarta(naipe, valor);
          cb2 = RetiraCartaGambiarra(cbR, debug);
          if(cb2 == NULL) {
            LiberaCarta(cbR);
          } else {
            printf("Carta retirada:\n");
            PrintaCelulaCarta(cbR);
            printf("Baralho apos a retirada da carta:\n");
            PrintaBaralho(debug);
            LiberaCarta(cb2);
            LiberaCarta(cbR);
          }
        }
      } else {
        printf("Erro: Baralho vazio ou nao existente.\n");
      }
    }
  }while (op != 4);
  LimparBaralhos(debug);
  printf("---------------- Fim do Modo Debug ----------------\n");
}
