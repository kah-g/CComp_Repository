#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

struct arv {
  char conteudo;
  Arv* esq;
  Arv* dir;
};

Arv* arv_criavazia (void) {
  /*
  Arv* arvere = (Arv*) malloc(sizeof(Arv));
  arvere->conteudo = NULL;
  arvere->esq = NULL;
  arvere->dir = NULL;
  return arvere;
  */
  return NULL;
}

Arv* arv_cria (char c, Arv* e, Arv* d) {
  Arv* arvere = (Arv*) malloc(sizeof(Arv));
  arvere->conteudo = c;
  arvere->esq = e;
  arvere->dir = d;
  return arvere;
}

Arv* arv_libera (Arv* a) {
  if(a == NULL) {
    return NULL;
  }
  arv_libera(a->esq);
  arv_libera(a->dir);
  free(a);
  return NULL;
}

int arv_vazia (Arv* a) {
  if(a == NULL) {
    return 1;
  }
  return 0;
}

int arv_pertence (Arv* a, char c) {
  if(a == NULL) {
    return 0;
  }
  return (a->conteudo == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c));
}

void arv_imprime (Arv* a) {
  if(a == NULL) {
    return;
  }
  printf("%c\n", a->conteudo);
  arv_imprime(a->esq);
  arv_imprime(a->dir);
}

Arv* arv_pai (Arv* a, char c) {
  if(a == NULL) {
    return NULL;
  }
  if(a->esq ==  NULL || a->dir == NULL) {
    return NULL;
  }
  if(a->esq->conteudo ==  c || a->dir->conteudo == c) {
    return a;
  }
  arv_pai(a->esq, c);
  arv_pai(a->dir, c);
}

int folhas (Arv* a) {
  if (a == NULL) {
    return 0;
  }
  if(a->esq == NULL && a->dir == NULL) {
    return 1;
  }
  return (folhas(a->esq) + folhas(a->dir));
}

int ocorrencias (Arv* a, char c) {
  if(a == NULL) {
    return 0;
  }
  return ((a->conteudo == c) + ocorrencias(a->esq, c) + ocorrencias(a->dir, c));
}

char info (Arv* a) {
  if((a == NULL) || (a->conteudo == NULL)) {
    return NULL;
  }
  return a->conteudo;
}

int altura (Arv* a) {
  //nao sei
}
