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
Carta* CortaBaralho (Baralho *brl);

void PrintaBaralho (Baralho *brl);
void PrintaCarta (Carta *ct);

#endif
