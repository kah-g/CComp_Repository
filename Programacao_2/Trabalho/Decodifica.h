#ifndef DECODIFICA_H
#define DECODIFICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DecodificarTexto (char playfar[5][5], char *textoCrip, char *textoDesencrip, int tamanho);
void Percorre2 (char letra, char matriz[5][5], int *linha, int *coluna);
void DecodificaMain (char *textoCrip, char matriz[5][5], char *textoDesencrip);

#endif
