#include "abb.h"

struct arv {
  int info;
  Tree* esq;
  Tree* dir;
};

Tree* CriaArvoreVazia () {
  return NULL;
}

void ImprimeCrescente(Tree* a) {
  if(a != NULL) {
    ImprimeCrescente(a->esq);
    printf("%d\n", a->info);
    ImprimeCrescente(a->dir);
  }
}

Tree* Insere(Tree* a, int info) {
  if(a == NULL) {
    a = (Tree*)malloc(sizeof(Tree));
    a-> info = info;
    a->esq = CriaArvoreVazia();
    a->dir = CriaArvoreVazia();
  } else if(info < a->info) {
    a->esq = Insere(a->esq, info);
  } else {
    a->dir = Insere(a->dir, info);
  }
  return a;
}

Tree* Busca(Tree* a, int info) {
  if(a == NULL) {
    return NULL;
  }
  if(info < a->info) {
    return Busca(a->esq, info);
  }
  if(info > a->info) {
    return Busca(a->dir, info);
  }
  return a;
}

Tree* Retira(Tree* a, int info) {
  if(a == NULL) {
    return NULL;
  } else if(info < a->info) {
    a->esq = Retira(a->esq, info);
  } else if(info > a->info) {
    a->dir = Retira(a->dir, info);
  } else {
    if(a->esq == NULL && a->dir == NULL) {
      free(a);
      a = NULL;
    } else if(a->esq == NULL) {
      Tree* t = a;
      a = a->dir;
      free(t);
    } else if(a->dir == NULL) {
      Tree* t = a;
      a = a->esq;
      free(t);
    } else {
      Tree* f = a->esq;
      while(f->dir != NULL) {
        f = f->dir;
      }
      a->info = f->info;
      f->info = info;
      a->esq = Retira(a->esq, info);
    }
  }
  return a;
}

void Libera(Tree* a) {
  if(a != NULL) {
    Libera(a->esq);
    Libera(a->dir);
    free(a);
  }
}
