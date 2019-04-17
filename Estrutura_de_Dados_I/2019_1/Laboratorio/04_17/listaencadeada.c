#include "listaencadeada.h"

int Vazia(TipoLista Lista) {
  //retorna 0 se estiver vazia e 1 no caso contrario
  if(Lista.Primeiro == NULL && Lista.Ultimo == NULL) {
    return 0;
  }
  TipoCelula* aux;
  aux = Lista.Primeiro;
  if (aux == Lista.Ultimo) {
    return 0;
  } else {
    return 1;
  }
}

void Insere(Produto x, TipoLista *Lista) {
  if(Lista->Primeiro == NULL) {
    Lista->Primeiro->Item = x;
    Lista->Primeiro->Prox = NULL;
    Lista->Ultimo->Item = x;
  } else {
    Lista->Ultimo->Prox->Item = x;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
  }
}
