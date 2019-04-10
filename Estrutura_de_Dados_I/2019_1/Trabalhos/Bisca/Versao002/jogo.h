#ifndef JOGO_H
#define JOGO_H

#include "baralho.h"

typedef struct jogador Jogador;
typedef struct celularjogador CelulaJogador;
typedef struct players Players;

void Menu ();
CelulaJogador* InicializaJogador ();
Players* InicializaJogo01 ();


void IniciaJogo ();
//Baralho* InicializaMaoVazia ();
void DistribuiCartas (Baralho *brl, Baralho *mao, Baralho *maoIA);

#endif
