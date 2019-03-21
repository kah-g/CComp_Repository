#include "Abb.h"

struct arv {
  char letra;
  int peso;
  int define_no; //0 se nao e no, 1 se for no
  Arv* esq;
  Arv* dir;
};

Arv* Cria_No (char letra, int peso) {
  Arv* arvere = (Arv*)malloc(sizeof(Arv));
  arvere->letra = letra;
  arvere->peso = peso;
  arvere->define_no = 1;
  arvere->esq = NULL;
  arvere->dir = NULL;
  return arvere;
}

int Retorna_Maior_Peso (Arv* a, Arv* b) {
  //verifica qual tem maior peso
  //retorna 0 se a de maior peso for a
  //retorna 1 se a de maior peso for b
  //retorna 2 se os pesos forem iguais
  if(a->peso > b->peso) {
    return 0;
  }
  if(b->peso > a->peso) {
    return 1;
  }
  return 2;
}

Arv* Cria_Arvore_Nos (Arv* a, Arv* b) {
  //cria uma arvore a partir de dois nos
  //com o peso sendo a soma do peso dos nos
  Arv* arvore = (Arv*)malloc(sizeof(Arv));
  arvore->letra = ']';
  arvore->peso = a->peso + b->peso;
  arvore->define_no = 0;
  arvore->esq = a;
  arvore->dir = b;
  return arvore;
}

void Imprime(Arv* a) {
  if(a != NULL) {
    Imprime_Crescente(a->esq);
    Imprime_Info_No(a);
    Imprime_Crescente(a->dir);
  }
}

Arv* Cria_Arvore_Vazia () {
  return NULL;
}

void Imprime_Info_No (Arv* x) {
  printf("letra: %c, peso: %d\n", x->letra, x->peso);
}

/*

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

*/
