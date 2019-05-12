#ifndef JOGO_H
#define JOGO_H

#include "baralho.h"

typedef struct jogador Jogador;
typedef struct celulajogador CelulaJogador;
typedef struct players Players;

void Menu ();
CelulaJogador* InicializaJogador ();
CelulaJogador* InicializaJogadorIA ();
int InicializaJogo (int tipoJogo, Players *jogadores, int* posP);
CelulaBaralho* JogadaReal (Jogador* jogg);
CelulaBaralho* JogadaIA (Jogador* jogg);
void LimparPlayers (Players *jogadores);
CelulaBaralho* JogadaIAD (Jogador* jogg, Carta* trunfo);

void IniciaJogo (int tipoJogo);
void DistribuiCartas (Baralho *brl, Players *jogadores);
void Debug ();

#endif
