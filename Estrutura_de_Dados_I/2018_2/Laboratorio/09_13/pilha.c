#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define TAM_MAX 10

//deu segfault uai?

struct pessoa {
  char* nome;
  int idade;
  char* endereco;
};

struct pilha {
  Pessoa item[TAM_MAX];
  int topo;
};

Pilha* cria_pilha() {
  Pilha* p = (Pilha*)malloc(sizeof(Pilha));
  p->topo = 0;
  return p;
}

void push(Pessoa* pessoa, Pilha* pilha) {
  if(pilha == NULL) {
    printf("Erro: Pilha não existe.\n");
    return;
  }
  if(pilha->topo == TAM_MAX) {
    printf("Erro: Pilha Cheia.\n");
    return;
  }
  pilha->topo++;
  pilha->item[pilha->topo] = *pessoa;
}

Pessoa* pop(Pilha* pilha) {
  if(pilha == NULL) {
    printf("Erro: Pilha não existe.\n");
    return NULL;
  }
  if(pilha->topo == 0) {
    printf("Erro: Pilha Vazia.\n");
    return NULL;
  }
  Pessoa* x = (Pessoa*)malloc(sizeof(Pessoa));
  *x = pilha->item[pilha->topo];
  pilha->topo--;
  return x;
}

void imprime_pilha (Pilha* pilha) {
  if(pilha == NULL) {
    printf("Erro: Pilha não existe.\n");
    return;
  }
  if(pilha->topo == 0) {
    printf("Erro: Pilha Vazia.\n");
    return;
  }
  for(int i=0; i < pilha->topo; i++) {
    printf("Nome: %s, Idade: %d, Endereco: %s.\n", pilha->item[i].nome, pilha->item[i].idade, pilha->item[i].endereco);
  }
}

Pilha* destroi_pilha(Pilha* pilha) {
  if(pilha == NULL) {
    printf("Erro: Pilha não existe.\n");
    return NULL;
  }
  if(pilha->topo == 0) {
    free(pilha);
    return pilha;
  }
  free(pilha);
  return pilha;
}

Pessoa* inicializaPessoa(char* nome, int idade, char* endereco) {
  //como verificar a validade de nome, idade e endereco?
  Pessoa* p = (Pessoa*)malloc(sizeof(Pessoa));
  strcpy(p->nome, nome);
  p->idade = idade;
  strcpy(p->endereco, endereco);
  return p;
}
