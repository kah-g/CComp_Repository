#ifndef GERAMATRIZ_H
#define GERAMATRIZ_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void PreencheMatriz(char matriz[5][5], char *vetorAbc);
int PercorreMatriz(char matriz[5][5], char *vetorAbc, int letra);
void PrintaMatriz(char matriz[5][5]);
void MatrizMain (int semente, char matriz[5][5]);

#endif
