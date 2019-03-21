#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RecebeLetra (char* letra);
int PercorrePalavra (char* letra, char* palavra);
void PreenchePalavra (char* letra, char* palavra, char* copia);
int Jogo (char* palavra, char* copia, char* letra);

int main () {
  //criar um jogo da forca

  //tem alguns erros

  //entrando com a palavra secreta
  printf("Bem vindos ao jogo da forca!\n");
  printf("Jogador 1, entre com a palavra secreta(tamanho maximo e 20 letras):\n");
  char* pSecreta = (char*)malloc(sizeof(char)*21);
  char* pCopia = (char*)malloc(sizeof(char)*21);
  char* pLetra = (char*)malloc(sizeof(char));
  scanf("%s", pSecreta);

  //zoando a tela pra esconder a palavra secreta
  int i;
  for (i=0; i < 22; i++) {
    printf("|....Aguarde....|\n");
  }
  printf("Vez do jogador 2:\n");

  //iniciando a palavra copia
  int tamanho;
  tamanho = strlen(pSecreta);
  for (i=0; i < tamanho; i++) {
    pCopia[i] = '*';
  }
  i++;
  pCopia[i] = '\0';

  //comecando o jogo
  int j=0, k;
  while (1) {
    setbuf(stdin,NULL);
    k = Jogo (pSecreta, pCopia, pLetra);
    j += k;
    printf("Erros: %d/5\n", j);
    if (!strcmp(pSecreta, pCopia) == 1) {
      printf("Parabens. Voce ganhou o jogo!\n");
      break;
    }
    if (j == 5) {
      printf("Perdeu Playboy!\n");
      break;
    }
  }

  //dando os frees
  free(pSecreta);
  free(pCopia);
  free(pLetra);

  return 0;
}

void RecebeLetra (char* letra) {
  printf("Digite uma letra: ");
  setbuf(stdin,NULL);
  scanf("%c", letra);
}

int PercorrePalavra (char* letra, char* palavra) {
  //retorna 1 se aquela letra pertence a palavra, 0 caso nao
  int tamanho, i;
  tamanho = strlen (palavra);
  for (i=0; i < tamanho; i++) {
    if (*letra == palavra[i]) {
      return 1;
    }
  }
  return 0;
}

void PreenchePalavra (char* letra, char* palavra, char* copia) {
  //verifica se aquela letra aparece mais de uma vez
  int tamanho, i, occ=0;
  tamanho = strlen (palavra);
  for (i=0; i < tamanho; i++) {
    if (*letra == palavra[i]) {
      occ++;
    }
  }

  if (occ >= 2) {
    //caso ocorra mais de uma vez
    int vtpnt[occ];
    //vtpnt e o vetor de posicoes da letra repetida
    int j=0;
    for (i=0; i < occ; i++) {
      if (*letra == palavra[i]) {
        vtpnt[j] = i;
        j++;
      }
    }
    for (i=0; i < occ; i++) {
      copia[vtpnt[i]] = *letra;
    }

  } else {
    //caso so ocorra uma vez
    for(i=0; i < tamanho; i++) {
      if (*letra == palavra[i]) {
        break;
      }
    }
    copia[i] = *letra;
  }

}

int Jogo (char* palavra, char* copia, char* letra) {
  //se a letra estiver errada retorna 1, se nao 0
  int verificador;
  RecebeLetra(letra);
  verificador = PercorrePalavra (letra, palavra);
  if (verificador == 0) {
    printf("%s\n", copia);
    return 1;
  } else if (verificador == 1) {
    PreenchePalavra (letra, palavra, copia);
    printf("%s\n", copia);
    return 0;
  }
}
