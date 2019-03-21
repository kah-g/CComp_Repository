#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Maior (int *notas, int notasN);
int Menor (int *notas, int notasN);
float Media (int *notas, int notasN);
float DesvioPadrao (int *notas, int notasN, float media);
int AcimaMdeia (int *notas, int notasN, float media);
int Reprovados (int *notas, int notasN);

int main () {
  int notasN, i;
  scanf("%d", &notasN);
  int notas[notasN];
  for (i=0; i < notasN; i++) {
    scanf("%d", &notas[i]);
  }
  int maior, menor, acimaMedia, reprovados;
  float media, desvioPadrao;

  maior = Maior (notas, notasN);
  menor = Menor (notas, notasN);
  media = Media (notas, notasN);
  desvioPadrao = DesvioPadrao (notas, notasN, media);
  acimaMedia = AcimaMdeia (notas, notasN, media);
  reprovados = Reprovados (notas, notasN);

  printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d\n", menor, maior, media, desvioPadrao, acimaMedia, reprovados);

  return 0;
}

int Maior (int *notas, int notasN) {
  int maior=-1, i;
  for (i=0; i < notasN; i++) {
    if (notas[i] > maior) {
      maior = notas[i];
    }
  }

  return maior;
}

int Menor (int *notas, int notasN) {
  int menor=101, i;
  for (i=0; i < notasN; i++) {
    if (notas[i] < menor) {
      menor = notas[i];
    }
  }

  return menor;
}

float Media (int *notas, int notasN) {
  int i;
  float media=0;
  for (i=0; i < notasN; i++) {
    media += notas[i];
  }
  media /= notasN;

  return media;
}

float DesvioPadrao (int *notas, int notasN, float media) {
  int i;
  float x=0.0,dp;
  for (i=1; i <= notasN; i++) {
    x += pow((notas[i-1] - media), 2);
  }
    x /= notasN;
    dp = sqrt (x);
    return dp;
}

int AcimaMdeia (int *notas, int notasN, float media) {
  int am=0, i;
  for (i=0; i < notasN; i++) {
    if (notas[i] > media) {
      am++;
    }
  }

  return am;
}

int Reprovados (int *notas, int notasN) {
  int reprovados=0, i;
  for (i=0; i < notasN; i++) {
    if (notas[i] < 70) {
      reprovados++;
    }
  }

  return reprovados;
}
