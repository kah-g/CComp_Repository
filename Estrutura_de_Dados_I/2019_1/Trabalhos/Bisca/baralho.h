#ifndef BARALHO_H
#define BARALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct carta Carta;
typedef struct celulaBaralho CelulaBaralho;
typedef struct baralho Baralho;

Baralho* InicializaBaralho ();
Baralho* InicializaBaralhoVazio ();
CelulaBaralho* RetiraCarta (int naipe, int valor, Baralho *brl);
void InsereCarta (CelulaBaralho *cb, Baralho *brl);
Baralho* EmbaralharBaralho (Baralho *brl);
Carta* CortaBaralho (Baralho *brl, int PontoCorte);
int VerificaBaralho (Baralho *brl);
CelulaBaralho* RetiraCartaTopo (Baralho *brl);
CelulaBaralho* RetiraCartaGambiarra (CelulaBaralho *carta, Baralho *brl);
CelulaBaralho* RetornaCartaPrim (Baralho *brl);
CelulaBaralho* RetornaCartaProx (CelulaBaralho* CartaAtual);
CelulaBaralho* RetornaCartaUlt (Baralho* brl);
int ComparaCartas (Baralho* brl, Carta* trunfo);
int ContagemPontos (Baralho *brl);
void LimparBaralhos (Baralho *brl);


void PrintaBaralho (Baralho *brl);
void PrintaCarta (Carta *ct);
void PrintaCelulaCarta (CelulaBaralho *ctbrl);
void PrintaBaralhoNumerado (Baralho *brl);

#endif
