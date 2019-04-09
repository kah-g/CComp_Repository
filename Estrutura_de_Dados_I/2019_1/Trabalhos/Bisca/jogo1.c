#include "jogo1.h"

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

Baralho* InicializaMaoVazia () {
  //mao e do tipo baralho pois possui a mesma estrutura
  Baralho *mao = InicializaBaralhoVazio();
  return mao;
}

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
