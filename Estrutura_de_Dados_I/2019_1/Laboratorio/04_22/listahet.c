#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listahet.h"

struct cliente {
  char* nome;
  int id;
};

struct movel {
  int placa;
  int ano;
  float valor;
};

struct imovel {
  int identificador;
  int ano;
  float valor;
};

struct listahet {
  Cliente* dono;
  void* item;
  ListaHet* prox;
  int identificadorItem;
};

ListaHet* cria () {
  ListaHet *lst01 = (ListaHet*) malloc(sizeof(ListaHet));
  lst01->dono = NULL;
  lst01->item = NULL;
  lst01->prox = NULL;
  lst01->identificadorItem = 0;
  return lst01;
}

Cliente* cria_cliente (char* nome, int id) {
  if(nome != NULL && id > 0) {
    Cliente *clt = (Cliente*) malloc(sizeof(Cliente));
    clt->nome = strdup(nome);
    clt->id = id;
    return clt;
  } else {
    printf("ERRO: Nome ou id invalidos. Nao foi possivel criar cliente.\n");
  }
}

Movel* cria_movel (int placa, int ano, float valor) {
  if((placa > 0) && (ano > 0) && (valor > 0)) {
    Movel *mvl = (Movel*) malloc(sizeof(Movel));
    mvl->placa = placa;
    mvl->ano = ano;
    mvl->valor = valor;
    return mvl;
  } else {
    printf("ERRO: Placa, ano ou valor invalidos. Nao foi possivel criar movel.\n");
  }
}

Imovel* cria_imovel (int id, int ano, float valor) {
  if((id > 0) && (ano > 0) && (valor > 0)) {
    Imovel *imvl = (Imovel*) malloc(sizeof(Imovel));
    imvl->identificador = id;
    imvl->ano = ano;
    imvl->valor = valor;
    return imvl;
  } else {
    printf("ERRO: Id, ano ou valor invalidos. Nao foi possivel criar imovel.\n");
  }
}

ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item) {
  if((lista != NULL) && (dono != NULL) && (item != NULL)) {

  } else {
    printf("ERRO: Lista, dono ou item invalidos. Nao foi possivel inserir imovel.\n");
  }
}
