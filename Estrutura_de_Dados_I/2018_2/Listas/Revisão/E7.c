#include <stdio.h>
#include <stdlib.h>

void PrintaMatriz (char** velha);
void Jogador (char** velha, int jogador);
void PreenchePos (char** velha, int linha, int coluna, int jogador);
int VerificaFim (char** velha);

int main () {
  //fazer um jogo da velha

  //criando e dando malloc na matriz
  char** velha = (char**)malloc(sizeof(int)*3);

  //criando o vetor de cada linha
  int i, j;
  for (i=0; i < 3; i++) {
    velha[i] = (char*)malloc(sizeof(char)*3);
  }

  //inicializando as posicoes
  for (i=0; i < 3; i++) {
    for (j=0; j < 3; j++) {
      velha[i][j] = '*';
    }
  }

  //comecando o jogo
  printf("Inicializando o jogo da velha...\n");
  PrintaMatriz(velha);
  int jogador, v;
  while (1) {
    //vez do jogador 1
    jogador = 1;
    Jogador(velha, jogador);
    v = VerificaFim(velha);
    if (v == 1) {
      printf("Jogador 1 ganhou!\n");
      break;
    }
    if (v == 2) {
      printf("Jogador 2 ganhou!\n");
      break;
    }
    if (v == 3) {
      printf("Xi! Deu velha!\n");
      break;
    }

    //vez do jogador 2
    jogador = 2;
    Jogador(velha, jogador);
    v = VerificaFim(velha);
    if (v == 1) {
      printf("Jogador 1 ganhou!\n");
      break;
    }
    if (v == 2) {
      printf("Jogador 2 ganhou!\n");
      break;
    }
    if (v == 3) {
      printf("Xi! Deu velha!\n");
      break;
    }
  }

  //dando free
  for (i=0; i < 3; i++) {
    free(velha[i]);
  }
  free(velha);

  return 0;
}

void PrintaMatriz (char** velha) {
  int i, j;
  for (i=0; i < 3; i++) {
    for (j=0; j < 3; j++) {
      printf("%c ", velha[i][j]);
    }
    printf("\n");
  }
}

void Jogador (char** velha, int jogador) {
  if (jogador == 1) {
    //jogador 1 = X
    printf("Jogador 1: ");
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);
    PreenchePos(velha, linha, coluna, jogador);
    PrintaMatriz(velha);
  } else if (jogador == 2) {
    //jogador 2 = O
    printf("Jogador 2: ");
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);
    PreenchePos(velha, linha, coluna, jogador);
    PrintaMatriz(velha);
  }

}

void PreenchePos (char** velha, int linha, int coluna, int jogador) {
  if (velha[linha][coluna] == '*') {
    if (jogador == 1) {
      velha[linha][coluna] = 'X';
    } else {
      velha[linha][coluna] = 'O';
    }
  } else {
    printf("Posicao ja ocupada!\n");
  }
}

int VerificaFim (char** velha) {
  //se retorna 1 jogador 1 ganhou, se 2 jogador 2 ganhou, se 3 deu velha, se 4 jogo nao acabou

  //verifica linhas
  int i, j;
  for (i=0; i < 3; i++) {
    if ((velha[i][0] == 'X') && (velha[i][1] == 'X') && (velha[i][2] == 'X')) {
      return 1;
    }
  }
  for (i=0; i < 3; i++) {
    if ((velha[i][0] == 'O') && (velha[i][1] == 'O') && (velha[i][2] == 'O')) {
      return 2;
    }
  }

  //verifica colunas
  for (i=0; i < 3; i++) {
    if ((velha[0][i] == 'X') && (velha[1][i] == 'X') && (velha[2][i] == 'X')) {
      return 1;
    }
  }
  for (i=0; i < 3; i++) {
    if ((velha[0][i] == 'O') && (velha[1][i] == 'O') && (velha[2][i] == 'O')) {
      return 2;
    }
  }

  //verifica diagonal
  if ((velha[0][0] == 'X') && (velha[1][1] == 'X') && (velha[2][2] == 'X')) {
    return 1;
  }
  if ((velha[0][2] == 'X') && (velha[1][1] == 'X') && (velha[2][0] == 'X')) {
    return 1;
  }
  if ((velha[0][0] == 'O') && (velha[1][1] == 'O') && (velha[2][2] == 'O')) {
    return 2;
  }
  if ((velha[0][2] == 'O') && (velha[1][1] == 'O') && (velha[2][0] == 'O')) {
    return 2;
  }

  //verifica se deu velha
  for (i=0; i < 3; i++) {
    for (j=0; j < 3; j++) {
      if (velha[i][j] == '*') {
        return 4;
      }
    }
  }
  return 3;
}
