#include "Codifica.h"

void CodificaMain (char *textoO, char matriz[5][5], char *textoEncrip) {
  char textoA[1000], textoB[1000];
  int tamanho=0;

  tamanho = strlen (textoO);
  RemoverEspaco (textoO, textoA, tamanho);
  printf("texto sem espaco: %s\n", textoA);
  //textoA e o texto sem espaços

  tamanho = strlen (textoA);
  DivisaoPares (textoA, textoB, tamanho);
  printf("texto dividido: %s\n", textoB);
  //textoB e o texto dividido em pares

  tamanho = strlen (textoB);
  CodificarTexto (matriz, textoB, textoEncrip, tamanho);
  printf("texto codificado: %s\n", textoEncrip);
  //textoEncrip e o texto codificado

}

void DivisaoPares (char *textoA, char *textoB, int tamanho) {
  //divide o texto em pares, seguindo a regra para caracteres repetidos
  //i percorre o texto original, j percorre o texto novo e k conta os espacos
  //l conta as vezes que x foi adicionado
  int i, j=0, k=0, l=0;

  for (i=0; i < tamanho;) {
    if (textoA[i] == textoA[i+1]) {
      textoB[j] = textoA[i];
      textoB[j+1] = 'X';
      j += 2;
      k++;
      i++;
      l++;
    } else {
      textoB[j] = textoA[i];
      if (i < (tamanho - 1)) {
        textoB[j+1] = textoA[i+1];
        j += 2;
        i += 2;
        k++;
      } else {
          break;
      }
    }
    if ((k == 1) && (i < (tamanho))) {
      textoB[j] = ' ';
      j++;
      k = 0;
    } else {
        break;
    }
  }

  j++;
  textoB[j] = '\0';
  //para confirmaR que nao sobrou nenhum caractere sozinho
  int tamanho2 = strlen (textoB);
  if ((((tamanho2 ) + l) % 2) != 0) {
    textoB[j] = 'X';
    textoB[j+1] = '\0';
  }
}

void RemoverEspaco (char *texto, char *textoA, int tamanho) {
  //copia o texto original para um novo eliminando os espaços
  int i, j=0;
  for (i=0; i < tamanho; i++) {
    if (texto[i] != ' ') {
      textoA[j] = texto[i];
      j++;
    }
  }
  textoA[j] = '\0';
}

void CodificarTexto (char matriz[5][5], char *textoB, char *textoEncrip, int tamanho) {
  //i percorre o texto encripitado e j percore o texto novo
  //k da os espacos no texto
  int i, j=0, k=0, linha1=0, coluna1=0, linha2=0, coluna2=0;
  for (i=0; i < tamanho;) {
    Percorre(textoB[i], matriz, &linha1, &coluna1);
    Percorre(textoB[i+1], matriz, &linha2, &coluna2);
    if (linha1 == linha2) {
      //se estiverem na mesma linha passam a ser o caractere da direita
      if (coluna1 == 4) {
        //se o primeiro caractere for o ultimo da linha
        textoEncrip[j] = matriz[linha1][0];
        textoEncrip[j+1] = matriz[linha2][coluna2 + 1];
      } else if (coluna2 == 4) {
        //se o segundo caractere for o ultimo da linha
        textoEncrip[j] = matriz[linha1][coluna1 + 1];
        textoEncrip[j+1] = matriz[linha2][0];
      } else {
        //caso nenhum deles seja o ultimo da linha
        textoEncrip[j] = matriz[linha1][coluna1 + 1];
        textoEncrip[j+1] = matriz[linha2][coluna2 + 1];
      }
    } else if (coluna1 == coluna2) {
      //se estiverem na mesma coluna passam a ser os caractere abaixo
      if (linha1 == 4) {
        //se o primeiro caractere for o ultimo da coluna
        textoEncrip[j] = matriz[0][coluna1];
        textoEncrip[j+1] = matriz[linha2 + 1][coluna2];
      } else if (linha2 == 4) {
        //se o segundo caractere for o ultimo da coluna
        textoEncrip[j] = matriz[linha1 + 1][coluna1];
        textoEncrip[j+1] = matriz[0][coluna2];
      } else {
        //caso nenhum deles seja o ultimo da coluna
        textoEncrip[j] = matriz[linha1 + 1][coluna1];
        textoEncrip[j+1] = matriz[linha2 + 1][coluna2];
      }
    } else {
      //se estiverem em linha e coluna diferentes
      textoEncrip[j] = matriz[linha1][coluna2];
      textoEncrip[j+1] = matriz[linha2][coluna1];
    }
    i += 3;
    j += 2;
    k++;
    if (k == 2) {
      //coloca os espacos no texto
      textoEncrip[j] = ' ';
      k = 0;
      j++;
    }
  }
  j++;
  textoEncrip[j] = '\0';
}

void Percorre (char letra, char matriz[5][5], int *linha, int *coluna) {
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
