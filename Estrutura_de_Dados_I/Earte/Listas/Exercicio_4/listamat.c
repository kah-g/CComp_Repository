#include "listamat.h"
#include <stdlib.h>
#include <stdio.h>

struct celulamatriz {
  Matriz* mtiz;
  Celulamatriz* prox;
  int chave; //posicao da matriz na lista
};

struct listamatriz {
  Celulamatriz* prim;
  Celulamatriz* ult;
  int qtt; //quantidade de matrizes na lista
};

Listamatriz* inicializalista () {
  Listamatriz* lista01 = (Listamatriz*) malloc (sizeof (Listamatriz));
  lista01->prim = NULL;
  lista01->ult = NULL;
  lista01->qtt = 0;
  return lista01;
}

void inserematriz (Listamatriz* lmat, Matriz* mat) {
  if (lmat != NULL && mat != NULL) {
    Celulamatriz* celm = (Celulamatriz*) malloc (sizeof(Celulamatriz));
    celm->mtiz = mat;
    celm->prox = NULL;
    celm->chave = 0;
    if (lmat->prim == NULL) {
      lmat->prim = celm;
      lmat->ult = celm;
      lmat->prim->chave = 1;
      lmat->qtt++;
    } else {
      celm->chave = (lmat->ult->chave) + 1;
      lmat->ult->prox = celm;
      lmat->ult = celm;
      lmat->qtt++;;
    }
  } else {
    printf("Erro: Lista ou matriz nula.\n");
  }
}

Matriz* retiramatriz (Listamatriz* lmat, int posicao) {
  if (lmat != NULL) {
    if (posicao > 0 && posicao <= lmat->qtt) {
      Celulamatriz* aux;
      Celulamatriz* ant;
      if (posicao == 1) {
        ant = lmat->prim;
        aux = ant->prox;
        lmat->prim = aux;
        while (aux != NULL){
          aux->chave--;
          aux = aux->prox;
        }
        lmat->qtt--;
        ant->chave = 0;
        Matriz* auxm = ant->mtiz;
        free(ant);
        return auxm;
      } else if (posicao == lmat->qtt) {
        ant = lmat->prim;
        aux = ant->prox;
        while (aux != lmat->ult) {
          ant = ant->prox;
          aux = ant->prox;
        }
        ant->prox = NULL;
        lmat->ult = ant;
        lmat->qtt--;
        aux->chave = 0;
        Matriz* auxm = aux->mtiz;
        free(aux);
        return auxm;
      } else {
        ant = lmat->prim;
        aux = lmat->prim->prox;
        while (aux->chave != posicao) {
          ant = ant->prox;
          aux = ant->prox;
        }
        ant->prox = aux->prox;
        ant = aux->prox;
        while (ant != NULL) {
          ant->chave--;
          ant = ant->prox;
        }
        lmat->qtt--;
        aux->chave = 0;
        Matriz* auxm = aux->mtiz;
        free(aux);
        return auxm;
      }
    } else {
      printf("Erro: Nao existe matriz na posicao %d.\n", posicao);
    }
  } else {
    printf("Erro: Lista nula.\n");
  }
}

void imprimelista (Listamatriz* lmat) {
  if (lmat != NULL) {
    printf("--- Imprimindo lista de tamanho %d ---\n", lmat->qtt);
    Celulamatriz* aux;
    aux = lmat->prim;
    while (aux != NULL) {
      printf("Matriz %d: \n", aux->chave);
      imprimeMatriz (aux->mtiz);
      aux = aux->prox;
      printf("\n");
    }
  } else {
    printf("Erro: Lista nula\n");
  }
}

void liberacelula (Celulamatriz* celmat) {
  if (celmat != NULL) {
    destroiMatriz (celmat->mtiz);
    free(celmat);
  } else {
    printf("Erro: Celula nula.\n");
  }
}

void liberalista (Listamatriz* lmat) {
  if (lmat != NULL) {
    Celulamatriz* ant;
    Celulamatriz* aux;
    ant = lmat->prim;
    aux = ant->prox;
    for (int i=0; i < lmat->qtt; i++) {
      liberacelula (ant);
      ant = aux;
      if (ant->prox != NULL) {
        aux = aux->prox;
      }
    }
    free(lmat);
  } else {
    printf("Erro: Lista nula.\n");
  }
}
