#include "Decodifica.h"

void DecodificaMain (char *textoCrip, char matriz[5][5], char *textoDesencrip) {
  int tamanho=0;

  tamanho = strlen (textoCrip);
  DecodificarTexto (matriz, textoCrip, textoDesencrip, tamanho);
  //printf("texto decodificado: %s\n", textoDesencrip);
}

void DecodificarTexto (char matriz[5][5], char *textoCrip, char *textoDesencrip, int tamanho) {
  //i percorre o texto codificado e j percore o texto novo
  //k da os espacos no texto
  //l pula os espacos do texto codificado
  int i, j=0, k=0, l=0, linha1=0, coluna1=0, linha2=0, coluna2=0;
  for (i=0; i < tamanho - 1;) {
    Percorre2(textoCrip[i], matriz, &linha1, &coluna1);
    Percorre2(textoCrip[i+1], matriz, &linha2, &coluna2);
    if (linha1 == linha2) {
      //se estiverem na mesma linha passam a ser o caractere da direita
      if (coluna1 == 0) {
        //se o primeiro caractere for o ultimo da linha
        textoDesencrip[j] = matriz[linha1][4];
        textoDesencrip[j+1] = matriz[linha2][coluna2 - 1];
      } else if (coluna2 == 0) {
        //se o segundo caractere for o ultimo da linha
        textoDesencrip[j] = matriz[linha1][coluna1 - 1];
        textoDesencrip[j+1] = matriz[linha2][4];
      } else {
        //caso nenhum deles seja o ultimo da linha
        textoDesencrip[j] = matriz[linha1][coluna1 - 1];
        textoDesencrip[j+1] = matriz[linha2][coluna2 - 1];
      }
    } else if (coluna1 == coluna2) {
      //se estiverem na mesma coluna passam a ser os caractere abaixo
      if (linha1 == 0) {
        //se o primeiro caractere for o ultimo da coluna
        textoDesencrip[j] = matriz[4][coluna1];
        textoDesencrip[j+1] = matriz[linha2 - 1][coluna2];
      } else if (linha2 == 0) {
        //se o segundo caractere for o ultimo da coluna
        textoDesencrip[j] = matriz[linha1 - 1][coluna1];
        textoDesencrip[j+1] = matriz[4][coluna2];
      } else {
        //caso nenhum deles seja o ultimo da coluna
        textoDesencrip[j] = matriz[linha1 - 1][coluna1];
        textoDesencrip[j+1] = matriz[linha2 - 1][coluna2];
      }
    } else {
      //se estiverem em linha e coluna diferentes
      textoDesencrip[j] = matriz[linha1][coluna2];
      textoDesencrip[j+1] = matriz[linha2][coluna1];
    }
    i += 2;
    j += 2;
    k++;
    l++;
    if (k == 1) {
      //coloca os espacos no texto
      textoDesencrip[j] = ' ';
      k = 0;
      j++;
    }
    if (l == 2) {
      i++;
      l = 0;
    }
  }
  j++;
  textoDesencrip[j] = '\n';
}

void Percorre2 (char letra, char matriz[5][5], int *linha, int *coluna) {
  //verifica em que linha e coluna esta aquela letra
  int i, j;
  for (i=0; i < 5; i++) {
    for (j=0; j < 5; j++) {
      if (letra == matriz[i][j]) {
        *linha = i;
        *coluna = j;
      }
    }
  }
}
