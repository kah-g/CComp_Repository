#include "baralho.h"

struct carta {
  //onde eu defino os naipes?
  int naipe;
  int valor;
  int pontos;
  int trunfo;
};

struct celulaBaralho {
  Carta *ct;
  CelulaBaralho *prox;
};

struct baralho {
  //maximo de cartas 40
  CelulaBaralho *prim;
  CelulaBaralho *ult;
  int quantidade;
};

Baralho* InicializaBaralho () {
  //cria o baralho e preenche com as cartas
  Baralho *brl = (Baralho*) malloc (sizeof(Baralho));
  brl->quantidade = 0;
  brl->prim = NULL;
  brl->ult = NULL;
  //iniciar cada naipe
  //ouros = 0, espadas = 1, copas = 2, paus = 3
  for(int i=0; i < 4; i++) {
    for(int j=1; j < 11; j++) {
      CelulaBaralho *cb = (CelulaBaralho*) malloc (sizeof(CelulaBaralho));
      if(brl->prim == NULL) {
        brl->prim = cb;
        brl->ult = cb;
      } else {
        brl->ult->prox = cb;
        brl->ult = cb;
        cb->prox = NULL;
      }
      cb->ct = (Carta*) malloc (sizeof(Carta));
      cb->ct->naipe = i;
      switch (j) {
        case 1:
          cb->ct->valor = 1;
          cb->ct->pontos = 11;
          break;
        case 2:
          cb->ct->valor = 2;
          cb->ct->pontos = 0;
          break;
        case 3:
          cb->ct->valor = 3;
          cb->ct->pontos = 0;
          break;
        case 4:
          cb->ct->valor = 4;
          cb->ct->pontos = 0;
          break;
        case 5:
          cb->ct->valor = 5;
          cb->ct->pontos = 0;
          break;
        case 6:
          cb->ct->valor = 6;
          cb->ct->pontos = 0;
          break;
        case 7:
          cb->ct->valor = 7;
          cb->ct->pontos = 10;
          break;
        case 8:
          cb->ct->valor = 11;
          cb->ct->pontos = 2;
          break;
        case 9:
          cb->ct->valor = 12;
          cb->ct->pontos = 3;
          break;
        case 10:
          cb->ct->valor = 13;
          cb->ct->pontos = 4;
          break;
      }
      brl->quantidade++;
    }
  }
  //printf("\nCartas: %d\n", brl->quantidade);
  return brl;
}

Baralho* InicializaBaralhoVazio () {
  Baralho *brl = (Baralho*) malloc (sizeof(Baralho));
  brl->quantidade = 0;
  brl->prim = NULL;
  brl->ult = NULL;
  return brl;
}

CelulaBaralho* RetiraCarta (int naipe, int valor, Baralho *brl) {
  CelulaBaralho *aux;
  CelulaBaralho *auxAnt;
  aux = brl->prim;
  //foi tentando usando && em um while so, mas dava erro de logica, o naipe de ouros era 0 entao o &&
  //sempre era verdadeiro
  while(aux != NULL && aux->ct->naipe != naipe && aux->ct->valor) {
    if(aux->prox == NULL) {
      printf("Erro: Carta nao esta neste baralho.\n");
      return NULL;
    }
    auxAnt = aux;
    aux = aux->prox;
  }
  while(aux != NULL && aux->ct->valor != valor) {
    if(aux->prox == NULL) {
      printf("Erro: Carta nao esta neste baralho.\n");
      return NULL;
    }
    auxAnt = aux;
    aux = aux->prox;
  }
  if(aux == brl->prim) {
    brl->prim = aux->prox;
    aux->prox = NULL;
    brl->quantidade--;
    return aux;
  }
  if(aux == brl->ult) {
    brl->ult = auxAnt;
    auxAnt->prox = NULL;
    brl->quantidade--;
    return aux;
  }
  auxAnt->prox = aux->prox;
  aux->prox = NULL;
  brl->quantidade--;
  return aux;
}

void InsereCarta (CelulaBaralho *cb, Baralho *brl) {
  if(brl->prim == NULL) {
    brl->prim = cb;
    brl->ult = cb;
  } else {
    brl->ult->prox = cb;
    brl->ult = cb;
  }
  brl->quantidade++;
}

Baralho* EmbaralharBaralho (Baralho *brl) {
  //o baralho original vai ser excluido
  Baralho* brlE = InicializaBaralhoVazio();
  CelulaBaralho* aux; //auxiliarpercorre o baralho original
  CelulaBaralho* aux2; //para auxilar na funcao que retira carta
  int aleatorio;
  srand(time(0));
  while(brl->quantidade > 0) {
    aux = brl->prim;
    aleatorio = rand()%brl->quantidade;
    //printf("%d\n", aleatorio);
    for(int i=0; i < aleatorio; i++) {
      aux = aux->prox;
    }
    aux2 = RetiraCarta(aux->ct->naipe, aux->ct->valor, brl);
    InsereCarta(aux2, brlE);
    /*printf("\n\nBaralho Original\n\n\n");
    PrintaBaralho(brl);
    printf("\nCartas O: %d\n\n", brl->quantidade);
    printf("\n\nBaralho Embaralhado\n\n\n");
    PrintaBaralho(brlE);
    printf("\nCartas E: %d\n\n", brlE->quantidade);
    */
  }
  free(brl); //esse baralho ja esta vazio
  return brlE;
}

Carta* CortaBaralho (Baralho *brl) {
  CelulaBaralho* aux; //percorre o baralho
  CelulaBaralho* aux2; //auxiliar na funcao retira
  Carta* trunfo;
  int aleatorio;
  srand(time(0));
  aux = brl->prim;
  aleatorio = rand()%brl->quantidade;
  for(int i=0; i < aleatorio; i++) {
    aux = aux->prox;
  }
  aux2 = RetiraCarta(aux->ct->naipe, aux->ct->valor, brl);
  trunfo = aux2->ct;
  InsereCarta(aux2, brl);
  return trunfo;
}

void PrintaBaralho (Baralho *brl) {
  CelulaBaralho *aux;
  aux = brl->prim;
  while(aux != NULL) {
    printf("Naipe: ");
    switch (aux->ct->naipe) {
      case 0:
        printf("OUROS  ,");
        break;
      case 1:
        printf("ESPADAS  ,");
        break;
      case 2:
        printf("COPAS  ,");
        break;
      case 3:
        printf("PAUS  ,");
        break;
    }
    printf("Valor: ");
    switch (aux->ct->valor) {
      case 1:
        printf("AS.");
        break;
      case 2:
        printf("2.");
        break;
      case 3:
        printf("3.");
        break;
      case 4:
        printf("4.");
        break;
      case 5:
        printf("5.");
        break;
      case 6:
        printf("6.");
        break;
      case 7:
        printf("7.");
        break;
      case 11:
        printf("VALETE.");
        break;
      case 12:
        printf("RAINHA.");
        break;
     case 13:
        printf("REI.");
        break;
    }
    printf("\n");
    aux = aux->prox;
  }
  printf("\nCartas: %d\n", brl->quantidade);
}

void PrintaCarta (Carta *ct) {
  printf("\n");
  printf("Naipe: ");
  switch (ct->naipe) {
    case 0:
      printf("OUROS  ,");
      break;
    case 1:
      printf("ESPADAS  ,");
      break;
    case 2:
      printf("COPAS  ,");
      break;
    case 3:
      printf("PAUS  ,");
      break;
  }
  printf("Valor: ");
  switch (ct->valor) {
    case 1:
      printf("AS.");
      break;
    case 2:
      printf("2.");
      break;
    case 3:
      printf("3.");
      break;
    case 4:
      printf("4.");
      break;
    case 5:
      printf("5.");
      break;
    case 6:
      printf("6.");
      break;
    case 7:
      printf("7.");
      break;
    case 11:
      printf("VALETE.");
      break;
    case 12:
      printf("RAINHA.");
      break;
   case 13:
      printf("REI.");
      break;
  }
  printf("\n\n");
}
