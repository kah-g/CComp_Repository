#include "Abb.h"

int Verifica_Arquivo (const char* arquivo);
Arv** Cria_Nos (int vetor[256]);
int Contador_Nos (int vetor[256]);
void Ordena_Vetor (Arv** Nos, int quantidade);
Arv* Unificador_Arvore (Arv** Nos, int quantidade);
void Imprime (Arv* arvore);


int main (int argc, char const** argv) {
  //testar o arquivo passado
  int i = Verifica_Arquivo(argv[1]);
  if(i == 0) {
    exit(1);
  }
  //abrindo e lendo o arquivo de entrada
  FILE *arq;
  arq = fopen(argv[1], "r");
  unsigned char letra;
  int alfabeto[256] = {0};
  while(fread(&letra, sizeof(unsigned char), 1, arq) == 1) {
    alfabeto[letra]++;
  }
  fclose(arq);

  //criando os nos da arvore
  Arv** Nos = Cria_Nos(alfabeto);

  //unindo os nos
  int tamanho = Contador_Nos(alfabeto);
  Arv* arvore = Unificador_Arvore(Nos, tamanho);
  free(Nos);
  Imprime(arvore);

  printf("Fim\n");

  return 0;
}

int Verifica_Arquivo (const char* arquivo) {
  //verifica se e possivel abrir aquele arquivo
  //retorna 0 se for null, e 1 caso contrario
  FILE *arq;
  arq = fopen(arquivo, "r");
  if(arq == NULL) {
    fclose(arq);
    printf("Nao foi possivel abrir o arquivo: %s\n", arquivo);
    return 0;
  }
  fclose(arq);
  return 1;
}

Arv** Cria_Nos (int vetor[256]) {
  //deve retornar um vetor de arvores, ja ordenado
  //sao criadas arvores apenas com peso maior que 0
  int tamanho = Contador_Nos(vetor);
  Arv** floresta = (Arv**)malloc(sizeof(Arv*)*tamanho);
  int j = 0;
  for(int i=0; i < 256; i++) {
    if(vetor[i] > 0) {
      floresta[j] = Cria_No(i, vetor[i]);
      j++;
    }
  }
  Ordena_Vetor(floresta, tamanho);
  return floresta;
}

int Contador_Nos (int vetor[256]) {
  //conta quantas letras tem no texto compactado
  int num = 0;
  for(int i=0; i < 256; i++) {
    if(vetor[i] > 0) {
      num++;
    }
  }
  return num;
}

void Ordena_Vetor (Arv** Nos, int quantidade) {
  Arv* aux;
  int k;
  for(int i=0; i < quantidade; i++) {
    for(int j=0; j < quantidade - i - 1; j++) {
      k = Retorna_Maior_Peso(Nos[j], Nos[j+1]);
      if(k == 0) {
        aux = Nos[j];
        Nos[j] = Nos[j+1];
        Nos[j+1] = aux;
      }
    }
  }
}

Arv* Unificador_Arvore (Arv** Nos, int quantidade) {
  //vai gerar uma unica arvore com o vetor de nos passado
  while(quantidade > 1) {
    Nos[0] = Cria_Arvore_Nos(Nos[0], Nos[1]);
    Nos[1] = Nos[quantidade-1];
    Nos[quantidade-1] = NULL;
    quantidade -= 1;
    Ordena_Vetor(Nos, quantidade);
    printf("Teste pos-Ordena_Vetor:\n");
  }
  return Nos[0];
}

void Imprime (Arv* arvore) {
  Imprime_Crescente(arvore);
}
