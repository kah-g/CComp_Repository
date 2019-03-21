#include "Terminal.h"

struct celulaterminal{
  Terminal* ter;
  Celulaterminal* prox;
};

struct terminal{
  char* nome;
  char* local;
  int rot;
};

struct listaterminal{
  Celulaterminal* prim;
  Celulaterminal* ult;
};

Listaterminal* InicializaListaTerminal(){
  Listaterminal* lt=(Listaterminal*)malloc(sizeof(Listaterminal));
  lt->prim = NULL;
  lt->ult = NULL;
  return lt;
}

int VerificaListaTerminal(Listaterminal* lt) {
  if (lt == NULL) {
    return 0;
  }
  return 1;
}

Terminal* CriaTerminal(char* nome, char* local) {
  Terminal* ter=(Terminal*)malloc(sizeof(Terminal));
  ter->nome = strdup(nome);
  ter->local = strdup(local);
  ter->rot = 0;
  return ter;
}

void InsereTerminal(Terminal* ter, Listaterminal* lt){
  Celulaterminal* nova=(Celulaterminal*)malloc(sizeof(Celulaterminal));
  if(lt->prim == NULL){
    lt->prim = lt->ult = nova;
  }else{
    lt->ult->prox = nova;
    lt->ult = lt->ult->prox;
  }
  lt->ult->ter = ter;
  lt->ult->prox = NULL;
}

Celulaterminal* RetiraTerminal(Listaterminal* lt, Terminal* ter){
  Celulaterminal* ant = NULL;
  Celulaterminal* p = lt->prim;
  while(p != NULL && p->ter->nome != ter->nome){
    ant = p;
    p = p->prox;
  }
  if(p == NULL){
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O terminal %s não esta nessa lista.\n\n", p->ter->nome);
    fclose(arqE);
    return NULL;
  }
  if(p == lt->prim && p == lt->ult){
    lt->prim = lt->ult = NULL;
    return p;
  }
  if(p == lt->ult){
    lt->ult = ant;
    ant->prox = NULL;
    return p;
  }
  if(p == lt->prim){
    lt->prim = p->prox;
  }else{
    ant->prox = p->prox;
  }
  return p;
}

int RetiraRoteadorDoTerminal(Terminal* ter) {
  if(ter->rot == 0) {
    return 0;
  }
  ter->rot = 0;
  return 1;
}

Terminal* ProcuraTerminal(char* nome, Listaterminal* lt) {
  Celulaterminal* aux = lt->prim;
  while(aux != NULL && strcmp(aux->ter->nome, nome)){
    aux = aux->prox;
  }
  if(aux == NULL){
    return NULL;
  }
  return aux->ter;
}

void ConectaRoteadorAoTerminal(Terminal* ter) {
  ter->rot = 1;
}

void DesconectaTerminalNaListaDeRoteadores(Listaterminal* lt) {
  Celulaterminal* aux = lt->prim;
  while(aux != NULL) {
    RetiraRoteadorDoTerminal(aux->ter);
    aux = aux->prox;
  }
}

int TerminalPorLocal(char* local, Listaterminal* lt) {
  int i = 0;
  Celulaterminal* aux = lt->prim;
  while(aux != NULL) {
    if(strcmp(local, aux->ter->local) == 0) {
      i++;
    }
    aux = aux->prox;
  }
  return i;
}

void LiberaTerminal(Celulaterminal* cllter) {
  free(cllter->ter->nome);
  free(cllter->ter->local);
  free(cllter->ter);
  free(cllter);
}

void LiberaListaTerminal(Listaterminal* lt) {
  Celulaterminal* aux = lt->prim;
  Celulaterminal* aux2;
  while(aux != NULL) {
    aux2 = aux;
    aux = aux->prox;
    LiberaTerminal(aux2);
  }
  free(lt);
}

char** ImprimeTerminais(Listaterminal* lt, int* ind) {
  int t = TamanhoListaTerminal(lt);
  char** vetorter = (char**)malloc(sizeof(char*)*t);
  for(int i=0; i < t; i++) {
    vetorter[i] = (char*)malloc(sizeof(char)*15);
  }
  Celulaterminal* aux = lt->prim;
  while(aux != NULL) {
    if(aux->ter->rot == 1) {
      strcpy(vetorter[(*ind)++], aux->ter->nome);
    } else {
      FILE *arqSd;
      arqSd = fopen("saida.dot", "a");
      fprintf(arqSd, "        %s;\n", aux->ter->nome);
      fclose(arqSd);
    }
    aux = aux->prox;
  }
  return vetorter;
}

int TamanhoListaTerminal(Listaterminal* lt) {
  Celulaterminal* aux = lt->prim;
  int tamanho = 0;
  while(aux != NULL) {
    tamanho++;
    aux = aux->prox;
  }
  return tamanho;
}
