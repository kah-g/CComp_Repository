#ifndef JOGO_H
#define JOGO_H

#include "baralho.h"

typedef struct jogador Jogador;
typedef struct celulajogador CelulaJogador;
typedef struct players Players;

void Menu ();
CelulaJogador* InicializaJogador ();
Players* InicializaJogo01 ();
CelulaBaralho* JogadaReal (Jogador* jogg);


void IniciaJogo (int tipoJogo);
void DistribuiCartas (Baralho *brl, Players *jogadores);

#endif
