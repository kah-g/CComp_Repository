#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct fila Fila;

Fila* criafila();
void inserefila(Fila* f, float v);

#endif
