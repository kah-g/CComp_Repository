#include "Roteador.h"

//Estruturas
struct celularoteador{
  Roteador* rot;
  Celularoteador* prox;
};

struct roteador{
  char* nome;
  char* operadora;
  Listaroteador* enlaces;
  Listaterminal* terminais;
  int flag;
};

struct listaroteador{
  Celularoteador* prim;
  Celularoteador* ult;
};

//Funcoes da TAD
Listaroteador* InicializaListaRoteador(){
  Listaroteador* lr = (Listaroteador*)malloc(sizeof(Listaroteador));
  lr->prim = NULL;
  lr->ult = NULL;
  return lr;
}

int VerificaListaRoteador(Listaroteador* lr) {
  if (lr == NULL) {
    return 0;
  }
  return 1;
}

Roteador* CriaRoteador(char* nome, char* operadora) {
  Roteador* rot = (Roteador*)malloc(sizeof(Roteador));
  rot->nome = strdup(nome);
  rot->operadora = strdup(operadora);
  rot->enlaces = NULL;
  rot->flag = 0;
  return rot;
}

void InsereRoteador(Roteador* rot, Listaroteador* lr){
  Celularoteador* nova = (Celularoteador*)malloc(sizeof(Celularoteador));
  if(lr->prim == NULL){
    lr->prim = lr->ult=nova;
  }else{
    lr->ult->prox = nova;
    lr->ult = nova;
  }
  lr->ult->rot = rot;
  lr->ult->prox = NULL;
}

void RetiraRoteador(Listaroteador* lr, Roteador* rot){
  Celularoteador* ant = NULL;
  Celularoteador* aux = lr->prim;
  while(aux != NULL && strcmp(aux->rot->nome, rot->nome)){
    ant = aux;
    aux = aux->prox;
  }
  if(aux->rot->enlaces != NULL) {
    //caso o roteador a ser retirado possui enlaces, todos eles deverão ser desfeitos
    //ou seja, essa e uma funcao retira roteador dentro da propria retira roteador
    Celularoteador* aux2 = aux->rot->enlaces->prim;
    while(aux != NULL) {
      DesfazEnlace(rot, aux2->rot);
      aux2 = aux2->prox;
    }
  }

  free(aux->rot->enlaces);

  if(aux->rot->terminais != NULL) {
    //caso o roteador a ser retirado possua uma lista de terminais, essa conexao deve ser desfeita
    DesconectaTerminalNaListaDeRoteadores(aux->rot->terminais);
  }
  free(aux->rot->terminais);
  if(aux == lr->prim && aux == lr->ult){
    lr->prim = lr->ult = NULL;
    free(aux->rot->nome);
    free(aux->rot->operadora);
    free(aux->rot);
    free(aux);
    return;
  }
  if(aux == lr->ult){
    lr->ult=ant;
    ant->prox = NULL;
    free(aux->rot->nome);
    free(aux->rot->operadora);
    free(aux->rot);
    return;
  }
  if(aux == lr->prim){
    lr->prim = aux ->prox;
  }else{
    ant->prox = aux->prox;
  }
  free(aux->rot->nome);
  free(aux->rot->operadora);
  free(aux->rot);
}

Roteador* ProcuraRoteador(char* nome, Listaroteador* lr) {
  Celularoteador* q = lr->prim;
  while(q != NULL && strcmp(q->rot->nome, nome)){
    q = q->prox;
  }
  if(q == NULL){
    return NULL;
  }
  return q->rot;
}

void RetiraTerminalDoRoteador(Terminal* ter, Roteador* rot) {
  RetiraTerminal(rot->terminais, ter);
}

void VerificaListaTerminalNoRoteador(Roteador* rot) {
  if(VerificaListaTerminal(rot->terminais) == 0) {
    rot->terminais = InicializaListaTerminal();
  }
}

void InsereTerminalNoRoteador(Roteador* rot, Terminal* ter) {
  InsereTerminal(ter, rot->terminais);
}

void EnlaceDeRoteador(Roteador* rot1, Roteador* rot2) {
  if(rot1->enlaces == NULL) {
    rot1->enlaces = InicializaListaRoteador();
  }
  if(rot2->enlaces == NULL) {
    rot2->enlaces = InicializaListaRoteador();
  }
  InsereRoteador(rot1, rot2->enlaces);
  InsereRoteador(rot2, rot1->enlaces);
}

void DesfazEnlace(Roteador* rot1, Roteador* rot2) {
  if((rot1->enlaces == NULL) || (rot2->enlaces == NULL)) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: Os roteadores %s e %s nao estao conectados.\n\n", rot1->nome, rot2->nome);
    fclose(arqE);
    return;
  }
  //desfazendo o enlace no rot1
  Celularoteador* ant = NULL;
  Celularoteador* aux = rot1->enlaces->prim;
  //procurando o rot2 na lista de enlaces do rot1
  while(aux != NULL && aux->rot->nome != rot2->nome){
    ant = aux;
    aux = aux->prox;
  }
  if(aux == rot1->enlaces->prim && aux == rot1->enlaces->ult){
    rot1->enlaces->prim = rot1->enlaces->ult = NULL;
  }
  if(aux == rot1->enlaces->ult){
    rot1->enlaces->ult = ant;
    ant->prox = NULL;
  }
  if(aux == rot1->enlaces->prim){
    rot1->enlaces->prim = aux->prox;
  }else{
    ant->prox = aux->prox;
  }
  //desfazendo o enlace no rot2
  ant = NULL;
  aux = rot2->enlaces->prim;
  //procurando o rot1 na lista de enlaces do rot2
  while(aux != NULL && aux->rot->nome != rot1->nome){
    ant = aux;
    aux = aux->prox;
  }
  if(aux == rot2->enlaces->prim && aux == rot2->enlaces->ult){
    rot2->enlaces->prim = rot2->enlaces->ult = NULL;
  }
  if(aux == rot2->enlaces->ult){
    rot2->enlaces->ult = ant;
    ant->prox = NULL;
  }
  if(aux == rot2->enlaces->prim){
    rot2->enlaces->prim = aux->prox;
  }else{
    ant->prox = aux->prox;
  }
}

int RoteadorPorOperadora(char* op, Listaroteador* lr) {
  int i = 0;
  Celularoteador* aux = lr->prim;
  while(aux != NULL) {
    if(strcmp(op, aux->rot->operadora) == 0) {
      i++;
    }
    aux = aux->prox;
  }
  return i;
}

void LiberaListaRoteador(Listaroteador* lr) {
  Celularoteador* aux = lr->prim, *aux2;
  while(aux != NULL){
    free(aux->rot->enlaces);
    free(aux->rot->terminais);
    free(aux->rot->nome);
    free(aux->rot->operadora);
    free(aux->rot);
    aux2 = aux;
    aux = aux->prox;
    free(aux2);
  }
  free(lr);
}

char* RetornaNomeRoteador(Roteador* rot) {
  return rot->nome;
}

void ImprimeRoteadores(Listaroteador* lr) {
  FILE *arqSd;
  arqSd = fopen("saida.dot", "a");
  Celularoteador* aux = lr->prim;
  Celularoteador* aux2;
  while(aux != NULL) {
    if(aux->rot->enlaces != NULL) {
      aux2 = aux->rot->enlaces->prim;
      while(aux2 != NULL) {
        fprintf(arqSd, "        %s -- %s;\n", aux->rot->nome, aux2->rot->nome);
        aux2 = aux2->prox;
      }
    } else {
        fprintf(arqSd, "        %s;\n", aux->rot->nome);
    }
    aux = aux->prox;
  }
  fclose(arqSd);
}

Roteador* ProcuraRoteadorPorTerminal(Listaroteador* lr, char* nometer) {
  Celularoteador* aux = lr->prim;
  Terminal* ter;
  while(aux != NULL) {
    if(aux->rot->terminais == NULL) {
      aux = aux->prox;
      continue;
    }
    ter = ProcuraTerminal(nometer, aux->rot->terminais);
    if(ter != NULL) {
      return aux->rot;
    }
    aux = aux->prox;
  }
  return NULL;
}

void ImprimeTerminaisConectados(char** nomester, Listaroteador* lr, int tam) {
  for(int i = 0; i < tam; i++) {
    Roteador* rot = ProcuraRoteadorPorTerminal(lr, nomester[i]);
    FILE *arqSd;
    arqSd = fopen("saida.dot", "a");
    fprintf(arqSd, "        %s -- %s;\n", nomester[i], rot->nome);
    fclose(arqSd);
  }
}
