#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listahet.h"

//Karinne Gomes - turma 01

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
  int identificadorItem; //1 para movel e 2 para imovel
};

ListaHet* cria () {
  /*
  ListaHet *lst01 = (ListaHet*) malloc(sizeof(ListaHet));
  lst01->dono = NULL;
  lst01->item = NULL;
  lst01->prox = NULL;
  lst01->identificadorItem = 0;*/
  ListaHet *lst01 = NULL;
  return lst01;
}

Cliente* cria_cliente (char* nome, int id) {
  if(nome != NULL && id > 0) {
    Cliente *clt = (Cliente*) malloc(sizeof(Cliente));
    clt->nome = strdup(nome);
    clt->id = id;
    return clt;
  } else {
    printf("ERRO: Nome ou id invalidos. Nao foi possivel criar cliente.\n\n");
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
    printf("ERRO: Placa, ano ou valor invalidos. Nao foi possivel criar movel.\n\n");
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
    printf("ERRO: Id, ano ou valor invalidos. Nao foi possivel criar imovel.\n\n");
  }
}

ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item) {
  if((dono != NULL) && (item != NULL)) {
    ListaHet *lst = (ListaHet*) malloc(sizeof(ListaHet));
    lst->dono = dono;
    lst->item = item;
    lst->identificadorItem = 1;
    lst->prox = lista;
    return lst;
  } else {
    printf("ERRO: Dono ou item invalidos. Nao foi possivel inserir movel.\n\n");
  }
}

ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item) {
  if((dono != NULL) && (item != NULL)) {
    ListaHet *lst = (ListaHet*) malloc(sizeof(ListaHet));
    lst->dono = dono;
    lst->item = item;
    lst->identificadorItem = 2;
    lst->prox = lista;
    return lst;
  } else {
    printf("ERRO: Dono ou item invalidos. Nao foi possivel inserir imovel.\n\n");
  }
}

void imprime (ListaHet* lista) {
  if(lista != NULL) {
    ListaHet *aux;
    aux = lista;
    while(aux != NULL) {
      printf("Dono: Nome:%s. Id:%d\n", aux->dono->nome, aux->dono->id);
      if(aux->identificadorItem == 1) {
        printf("Movel: Placa: %d. Ano: %d. Valor: %.2f.\n", ((Movel*) aux->item)->placa, ((Movel*) aux->item)->ano, ((Movel*) aux->item)->valor);
      } else {
        printf("Imovel: Identificador: %d. Ano: %d. Valor: %.2f.\n", ((Imovel*) aux->item)->identificador, ((Imovel*) aux->item)->ano, ((Imovel*) aux->item)->valor);
      }
      aux = aux->prox;
      printf("\n");
    }
  } else {
    printf("ERRO: Lista invalida. Nao foi possivel imprimir.\n\n");
  }
}

ListaHet* retira_cliente (ListaHet* lista, int id_cliente) {
  if(lista != NULL) {
    ListaHet *aux, *ant, *aux2;
    Cliente *auxC;
    aux2 = lista;
    aux = lista;
    ant = NULL;
    while(aux != NULL) {
      if(aux->dono->id == id_cliente) {
        if(ant == NULL) {
          auxC = aux->dono;
          free(aux->item);
          aux2 = aux;
          free(aux);
        } else {
          auxC = aux->dono;
          ant->prox = aux->prox;
          free(aux->item);
          free(aux);
        }
      }
      ant = aux;
      aux = aux->prox;
    }
    free(auxC);
    return aux2;
  } else {
    printf("ERRO: Lista invalida. Nao foi possivel retirar cliente.\n\n");
    return lista;
  }
}

float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel) {
  if(lista != NULL && dono != NULL) {
    ListaHet *aux;
    float soma = 0;
    aux = lista;
    while(aux != NULL) {
      if(aux->dono == dono) {
        if(aux->identificadorItem == 1) {
          soma+=(((Movel*)aux->item)->valor * taxa_movel);
        }
        if(aux->identificadorItem == 2) {
          soma+=(((Imovel*)aux->item)->valor * taxa_imovel);
        }
      }
      aux = aux->prox;
    }
    return soma;
  } else {
    printf("ERRO: Lista ou dono invalidos. Nao foi possivel calcular valor.\n\n");
  }
}
