#ifndef GERASEMENTE_H
#define GERASEMENTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//funcoes
int ConverteMaiuscula (char *senha);

int ConverteMinuscula (char *senha);

int ConverteNumero (char *senha);

void LeQuantidades (char *senha, int tamanho, int *maiuscula, int *minuscula, int *numeros);

int SementeMain (char *senha);

#endif
