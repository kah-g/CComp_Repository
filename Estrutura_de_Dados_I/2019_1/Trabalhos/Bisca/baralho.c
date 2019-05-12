#include "baralho.h"

struct carta {
  int naipe;
  int valor;
  int pontos;
};

struct celulaBaralho {
  Carta *ct;
  CelulaBaralho *prox;
};

struct baralho {
  CelulaBaralho *prim;
  CelulaBaralho *ult;
  int quantidade; //maximo de cartas 40
};

Baralho* InicializaBaralho () {
  //cria o baralho e preenche com as cartas
  Baralho *brl = (Baralho*) malloc (sizeof(Baralho));
  brl->quantidade = 0;
  brl->prim = NULL;
  brl->ult = NULL;
  //iniciar cada naipe
  //ouros = 1, espadas = 2, copas = 3, paus = 4
  for(int i=0; i < 4; i++) {
    for(int j=1; j < 11; j++) {
      CelulaBaralho *cb = (CelulaBaralho*) malloc (sizeof(CelulaBaralho));
      if(brl->prim == NULL) {
        brl->prim = cb;
        brl->ult = cb;
      } else {
        brl->ult->prox = cb;
        brl->ult = cb;
        cb->prox = NULL;
      }
      cb->ct = (Carta*) malloc (sizeof(Carta));
      cb->ct->naipe = i+1;
      switch (j) {
        case 1:
          cb->ct->valor = 14; //as
          cb->ct->pontos = 11;
          break;
        case 2:
          cb->ct->valor = 2;
          cb->ct->pontos = 0;
          break;
        case 3:
          cb->ct->valor = 3;
          cb->ct->pontos = 0;
          break;
        case 4:
          cb->ct->valor = 4;
          cb->ct->pontos = 0;
          break;
        case 5:
          cb->ct->valor = 5;
          cb->ct->pontos = 0;
          break;
        case 6:
          cb->ct->valor = 6;
          cb->ct->pontos = 0;
          break;
        case 7:
          cb->ct->valor = 7;
          cb->ct->pontos = 10;
          break;
        case 8:
          cb->ct->valor = 11;
          cb->ct->pontos = 2;
          break;
        case 9:
          cb->ct->valor = 12;
          cb->ct->pontos = 3;
          break;
        case 10:
          cb->ct->valor = 13;
          cb->ct->pontos = 4;
          break;
      }
      brl->quantidade++;
    }
  }
  //printf("\nCartas: %d\n", brl->quantidade);
  return brl;
}

Baralho* InicializaBaralhoVazio () {
  Baralho *brl = (Baralho*) malloc (sizeof(Baralho));
  brl->quantidade = 0;
  brl->prim = NULL;
  brl->ult = NULL;
  return brl;
}

CelulaBaralho* RetiraCarta (int naipe, int valor, Baralho *brl) {
  CelulaBaralho *aux;
  CelulaBaralho *auxAnt;
  aux = brl->prim;
  //foi tentando usando && em um while so, mas dava erro de logica, o naipe de ouros era 0 entao o &&
  //sempre era verdadeiro
  while(aux != NULL && (aux->ct->naipe != naipe || aux->ct->valor != valor)) {
    if(aux->prox == NULL) {
      printf("Erro: Carta nao esta neste baralho.\n");
      return NULL;
    }
    auxAnt = aux;
    aux = aux->prox;
  }
  /*while(aux != NULL && aux->ct->valor != valor) {
    if(aux->prox == NULL) {
      printf("Erro: Carta nao esta neste baralho.\n");
      return NULL;
    }
    auxAnt = aux;
    aux = aux->prox;
  }*/
  if(aux == brl->prim) {
    brl->prim = aux->prox;
    aux->prox = NULL;
    brl->quantidade--;
    return aux;
  }
  if(aux == brl->ult) {
    brl->ult = auxAnt;
    auxAnt->prox = NULL;
    brl->quantidade--;
    return aux;
  }
  auxAnt->prox = aux->prox;
  aux->prox = NULL;
  brl->quantidade--;
  return aux;
}

void InsereCarta (CelulaBaralho *cb, Baralho *brl) {
  if(brl->prim == NULL) {
    brl->prim = cb;
    brl->ult = cb;
  } else {
    brl->ult->prox = cb;
    brl->ult = cb;
  }
  brl->quantidade++;
}

Baralho* EmbaralharBaralho (Baralho *brl) {
  //o baralho original vai ser excluido
  Baralho* brlE = InicializaBaralhoVazio();
  CelulaBaralho* aux; //auxiliarpercorre o baralho original
  CelulaBaralho* aux2; //para auxilar na funcao que retira carta
  int aleatorio;
  srand(time(0));
  while(brl->quantidade > 0) {
    aux = brl->prim;
    aleatorio = rand()%brl->quantidade;
    //printf("%d\n", aleatorio);
    for(int i=0; i < aleatorio; i++) {
      aux = aux->prox;
    }
    aux2 = RetiraCarta(aux->ct->naipe, aux->ct->valor, brl);
    InsereCarta(aux2, brlE);
  }
  free(brl); //esse baralho ja esta vazio
  return brlE;
}

Carta* CortaBaralho (Baralho *brl, int PontoCorte) {
  CelulaBaralho* aux; //percorre o baralho
  CelulaBaralho* aux2; //auxiliar na funcao retira
  Carta* trunfo;
  //int aleatorio;
  //srand(time(0));
  aux = brl->prim;
  PontoCorte--;
  //aleatorio = rand()%brl->quantidade;
  for(int i=0; i < PontoCorte; i++) {
    aux = aux->prox;
  }
  aux2 = RetiraCarta(aux->ct->naipe, aux->ct->valor, brl);
  trunfo = aux2->ct;
  InsereCarta(aux2, brl);
  return trunfo;
}

int VerificaBaralho (Baralho *brl) {
  //retorna a quantidade de cartas naquele baralho
  if(brl == NULL) {
    return -1; //baralho nao inicializado
  }
  if(brl->prim == NULL && brl->ult == NULL) {
    return 0; //baralho vazio
  } else {
    return brl->quantidade; //retorna a quantidade de cartar no baralho
  }
}

CelulaBaralho* RetiraCartaTopo (Baralho *brl) {
  CelulaBaralho *aux;
  if (VerificaBaralho(brl) == 0 || VerificaBaralho(brl) == -1) {
    printf("ERRO: Baralho vazio ou nulo.\n");
    exit(1);
  }
  aux = brl->prim;
  if(brl->quantidade == 1) {
    brl->prim = NULL;
    brl->ult = NULL;
    brl->quantidade--;
    return aux;
  }
  brl->prim = aux->prox;
  aux->prox = NULL;
  brl->quantidade--;
  return aux;
}

CelulaBaralho* RetiraCartaGambiarra (CelulaBaralho *carta, Baralho *brl){
  //mesma funcao que a retira carta porem nao passando as informacoes da carta
  //inclusive utiliza a funcao retira carta original
  return RetiraCarta(carta->ct->naipe, carta->ct->valor, brl);
}

CelulaBaralho* RetornaCartaPrim (Baralho *brl) {
  //retorna brl->prim, obviously
  return brl->prim;
}

CelulaBaralho* RetornaCartaProx (CelulaBaralho* CartaAtual) {
  //o nome diz tudo
  return CartaAtual->prox;
}

CelulaBaralho* RetornaCartaUlt (Baralho* brl) {
  //nome auto-explicativo
  return brl->ult;
}

int ComparaCartas (Baralho* brl, Carta* trunfo) {
  //retorna a posicao da maior Carta
  //todas as cartas vao pro monte do jogador que estiver naquela posicao
  int num = 0, Pos;
  int np0 = 0, np1 = 0, np2 = 0, np3 = 0;
  int vl0 = 0, vl1 = 0, vl2 = 0, vl3 = 0;
  //np0 e vl0 equivalem a ouro que e o naipe 1
  //np1 e vl1 equivalem a espadas que e o naipe 2
  //np2 e vl2 equivalem a copas que e o naipe 3
  //np3 e vl3 equivalem a paus que e o naipe 4
  CelulaBaralho *aux = brl->prim;
  for(int i=0; i < brl->quantidade; i++) {
    if(aux->ct->naipe == trunfo->naipe) {
      if(num != 0) {
        if(num < aux->ct->valor) {
          num = aux->ct->valor;
          Pos = i;
        }
      } else {
        num = aux->ct->valor;
        Pos = i;
      }
    }
    if(aux->ct->naipe != trunfo->naipe) {
      if(aux->ct->naipe == 1) {
        np0++;
        if(vl0 != 0) {
          if(aux->ct->valor > vl0) {
            vl0 = aux->ct->valor;
          }
        } else {
          vl0 = aux->ct->valor;
        }
      }
      if(aux->ct->naipe == 2) {
        np1++;
        if(vl1 != 0) {
          if(aux->ct->valor > vl1) {
            vl1 = aux->ct->valor;
          }
        } else {
          vl1 = aux->ct->valor;
        }
      }
      if(aux->ct->naipe == 3) {
        np2++;
        if(vl2 != 0) {
          if(aux->ct->valor > vl2) {
            vl2 = aux->ct->valor;
          }
        } else {
          vl2 = aux->ct->valor;
        }
      }
      if(aux->ct->naipe == 4) {
        np3++;
        if(vl3 != 0) {
          if(aux->ct->valor > vl3) {
            vl3 = aux->ct->valor;
          }
        } else {
          vl3 = aux->ct->valor;
        }
      }
    }
    aux = aux->prox;
  }
  if(num != 0) {
    return Pos;
  } else {
    if((np0 > 1) || (np1 > 1) || (np2 > 1) || (np3 > 1)) {
      CelulaBaralho *aux = brl->prim;
      if((np0 > 1) && !((np1 > 1) || (np2 > 1 || (np3 > 1)))) {
        for(int i=0; i < brl->quantidade; i++) {
          if(aux->ct->naipe == 1 && aux->ct->valor == vl0) {
            return i;
          }
          aux = aux->prox;
        }
      }
      if((np1 > 1) && !((np0 > 1) || (np2 > 1 || (np3 > 1)))) {
        for(int i=0; i < brl->quantidade; i++) {
          if(aux->ct->naipe == 2 && aux->ct->valor == vl1) {
            return i;
          }
          aux = aux->prox;
        }
      }
      if((np2 > 1) && !((np1 > 1) || (np0 > 1 || (np3 > 1)))) {
        for(int i=0; i < brl->quantidade; i++) {
          if(aux->ct->naipe == 3 && aux->ct->valor == vl2) {
            return i;
          }
          aux = aux->prox;
        }
      }
      if((np3 > 1) && !((np1 > 1) || (np2 > 1 || (np0 > 1)))) {
        for(int i=0; i < brl->quantidade; i++) {
          if(aux->ct->naipe == 4 && aux->ct->valor == vl3) {
            return i;
          }
          aux = aux->prox;
        }
      }
    }
    return 0;
  }
}

int ContagemPontos (Baralho *brl) {
  int pontos = 0;
  CelulaBaralho *aux = brl->prim;
  for(int i=0; i < brl->quantidade; i++) {
    pontos+= aux->ct->pontos;
    aux = aux->prox;
  }
  return pontos;
}

void LimparBaralhos (Baralho *brl) {
  CelulaBaralho *aux = brl->prim;
  if(aux == NULL || brl->quantidade == 0) {
    free(brl);
  } else {
    if(brl->quantidade > 1) {
      CelulaBaralho *aux2;
      for(int i=0; i < brl->quantidade; i++) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2->ct);
        free(aux2);
      }
      free(brl);
    } else {
      if(brl->quantidade == 1) {
        free(aux->ct);
        free(aux);
        free(brl);
      }
    }
  }
}

int ComparaCartasIa (Baralho* brl, Carta* trunfo) {
  //retorna a posicao da melhor carta a ser jogada
  int num = 0, Pos, trf = 0;
  CelulaBaralho *aux = brl->prim;
  for(int i=0; i < brl->quantidade; i++) {
    if(aux->ct->naipe == trunfo->naipe) {
      trf = 1;
      if(num != 0) {
        if(num < aux->ct->valor) {
          num = aux->ct->valor;
          Pos = i;
        }
      } else {
        num = aux->ct->valor;
        Pos = i;
      }
    }
    if(aux->ct->naipe != trunfo->naipe && trf == 0) {
      if(aux->ct->valor > num) {
        num = aux->ct->valor;
        Pos = i;
      }
    }
    aux = aux->prox;
  }
  if(trf == 1) {
    return Pos;
  } else {
    srand(time(0));
    int alt = rand()%2; //isso e um sorteio pra decididir se ele vai
    //jogar a maior carta ou se vai jogar uma carta aleatoria
    if(alt == 0) {
      //em caso 0 joga a maior Carta
      return Pos;
    }
    if(alt == 1) {
      //em caso 1 joga uma carta aleatoria
      Pos = rand()%brl->quantidade;
      return Pos;
    }
  }
}

void PrintaBaralho (Baralho *brl) {
  CelulaBaralho *aux;
  aux = brl->prim;
  while(aux != NULL) {
    printf("Naipe: ");
    switch (aux->ct->naipe) {
      case 1:
        printf("OUROS  ,");
        break;
      case 2:
        printf("ESPADAS  ,");
        break;
      case 3:
        printf("COPAS  ,");
        break;
      case 4:
        printf("PAUS  ,");
        break;
    }
    printf("Valor: ");
    switch (aux->ct->valor) {
      case 14:
        printf("AS.");
        break;
      case 2:
        printf("2.");
        break;
      case 3:
        printf("3.");
        break;
      case 4:
        printf("4.");
        break;
      case 5:
        printf("5.");
        break;
      case 6:
        printf("6.");
        break;
      case 7:
        printf("7.");
        break;
      case 11:
        printf("VALETE.");
        break;
      case 12:
        printf("RAINHA.");
        break;
     case 13:
        printf("REI.");
        break;
    }
    printf("\n");
    aux = aux->prox;
  }
  printf("Cartas: %d\n\n", brl->quantidade);
}

void PrintaCarta (Carta *ct) {
  printf("Naipe: ");
  switch (ct->naipe) {
    case 1:
      printf("OUROS  ,");
      break;
    case 2:
      printf("ESPADAS  ,");
      break;
    case 3:
      printf("COPAS  ,");
      break;
    case 4:
      printf("PAUS  ,");
      break;
  }
  printf("Valor: ");
  switch (ct->valor) {
    case 14:
      printf("AS.");
      break;
    case 2:
      printf("2.");
      break;
    case 3:
      printf("3.");
      break;
    case 4:
      printf("4.");
      break;
    case 5:
      printf("5.");
      break;
    case 6:
      printf("6.");
      break;
    case 7:
      printf("7.");
      break;
    case 11:
      printf("VALETE.");
      break;
    case 12:
      printf("RAINHA.");
      break;
   case 13:
      printf("REI.");
      break;
  }
  printf("\n\n");
}

void PrintaCelulaCarta (CelulaBaralho *ctbrl) {
  //printa a carta mas recebendo a celula baralho
  PrintaCarta(ctbrl->ct);
}

void PrintaBaralhoNumerado (Baralho *brl) {
  //mesma coisa que o PrintaBaralho porem coloca numeracao antes das cartas
  CelulaBaralho *aux;
  aux = brl->prim;
  int i = 1;
  while(aux != NULL) {
    printf("%d - Naipe: ", i);
    switch (aux->ct->naipe) {
      case 1:
        printf("OUROS  ,");
        break;
      case 2:
        printf("ESPADAS  ,");
        break;
      case 3:
        printf("COPAS  ,");
        break;
      case 4:
        printf("PAUS  ,");
        break;
    }
    printf("Valor: ");
    switch (aux->ct->valor) {
      case 14:
        printf("AS.");
        break;
      case 2:
        printf("2.");
        break;
      case 3:
        printf("3.");
        break;
      case 4:
        printf("4.");
        break;
      case 5:
        printf("5.");
        break;
      case 6:
        printf("6.");
        break;
      case 7:
        printf("7.");
        break;
      case 11:
        printf("VALETE.");
        break;
      case 12:
        printf("RAINHA.");
        break;
     case 13:
        printf("REI.");
        break;
    }
    printf("\n");
    aux = aux->prox;
    i++;
  }
  printf("Cartas: %d\n\n", brl->quantidade);
}

CelulaBaralho* CriaCarta (int naipe, int valor) {
  CelulaBaralho *cb = (CelulaBaralho*) malloc (sizeof(CelulaBaralho));
  cb->ct = (Carta*) malloc (sizeof(Carta));
  cb->ct->naipe = naipe;
  cb->ct->valor = valor;
  return cb;
}

void LiberaCarta (CelulaBaralho* ct) {
  free(ct->ct);
  free(ct);
}
