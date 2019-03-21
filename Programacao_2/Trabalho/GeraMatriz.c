#include "GeraMatriz.h"

void MatrizMain (int semente, char matriz[5][5]) {
  //matriz e vetor com as letras
  char vetorAbc[26]="ABCDEFGHIJKLMNOPQRSTUVWXZ";

  //definindo a semente
  srand(semente);

  PreencheMatriz(matriz, vetorAbc);

  //PrintaMatriz(matriz);

}

void PreencheMatriz(char matriz[5][5], char *vetorAbc) {
  //percorre a matriz e a preenche, verificando se há repetidas
  //m preenche a vetor matriz
  int letra,i,j, letra2;
  for (i=0; i < 5; i++) {
    for (j=0; j <5; j++) {
      //o valor maximo da rand
      letra = rand() % 24;
      if (PercorreMatriz(matriz, vetorAbc, letra) == 0) {
        //quando nao e repetida ele preenche aquela posicao da matriz com a letra
        matriz[i][j] = vetorAbc[letra];
      } else {
          //quando e repetida ele verifica em ordem alfabetica qual a primeira letra que ainda não foi usada
          //e preenche aquela posicao com a letra
          letra2 = 0;
          while (PercorreMatriz(matriz, vetorAbc, letra2) == 1) {
              letra2++;
          }
          matriz[i][j] = vetorAbc[letra2];
        }
      }
    }
  }

int PercorreMatriz(char matriz[5][5], char *vetorAbc, int letra) {
  //verifica se aquela letra já esta na matriz
  int i, j;
  for (i=0; i < 5; i++) {
    for (j=0; j < 5; j++) {
      if (matriz[i][j] == vetorAbc[letra]) {
        return 1;
      }
    }
  }
  return 0;
}


void PrintaMatriz(char matriz[5][5]) {
  //imprime a matriz
  int i,j;
  for (i=0; i < 5; i++) {
    for (j=0; j <5; j++) {
      printf("%c ", matriz[i][j]);
    }
    printf("\n");
  }
}
