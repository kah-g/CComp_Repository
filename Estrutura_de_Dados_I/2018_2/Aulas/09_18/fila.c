#include "fila.h"

struct fila {
  int n;
  int ini;
  float vet[N];
};

Fila* criafila() {
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f->n = 0;
  f->ini = 0;
  return f;
}

void inserefila(Fila* f, float v) {
  if(f == NULL) {
    printf("Erro: Fila não existe.\n");
    return;
  }
  if(f->n == N) {
    printf("Erro: Fila cheia.\n");
    return;
  }
  int fim = (f->n + f->ini) % N;
  f->vet[fim] = v;
}
