#include "baralho.h"

struct carta {
  //onde eu defino os naipes?
  char naipe;
  char valor;
  int pontos;
};

struct celulaBaralho {
  Carta *ct;
  CelulaBaralho *prox;
};

struct baralho {
  //maximo de cartas 40
  CelulaBaralho *prim;
  CelulaBaralho *ult;
  int quantidade;
};

Baralho* InicializaBaralho () {
  //cria o baralho
  Baralho *brl = (Baralho*) malloc (sizeof(Baralho));
  //iniciar cada naipe
  //ouros - representado por O - 10 cartas
  for(int i=0; i < 10; i++) {
    CelulaBaralho *cb = (CelulaBaralho*) malloc (sizeof(CelulaBaralho));
    cb->ct = (Carta*) malloc (sizeof(Carta));
    cb->ct->naipe = 'O';
  }
}
