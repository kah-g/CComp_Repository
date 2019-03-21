#ifndef CODIFICA_H
#define CODIFICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DivisaoPares (char *textoA, char *textoB, int tamanho);
void RemoverEspaco (char *texto, char *textoA, int tamanho);
void CodificarTexto (char matriz[5][5], char *textoB, char *textoEncrip, int tamanho);
void Percorre (char letra, char matriz[5][5], int *linha, int *coluna);
void CodificaMain (char *textoO, char matriz[5][5], char *textoEncrip);


#endif
