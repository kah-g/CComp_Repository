#include "Principal.h"

int main () {
  int op;
  printf("------SEJA BEM VINDO AO ENCRIPTADOR TECPIX------\n");
  printf("ESCOLHA UMA DAS OPCOES ABAIXO:\n 1.ENCRIPTAR\n 2.DESENCRIPTAR\n");
  scanf("%d", &op);
  switch (op) {
    case 1:
      Encriptar ();
      break;
    case 2:
      Desencriptar ();
      break;
    default:
      printf("OPCAO INVALIDA\n");
      exit(1);
  }

  return 0;
}

void Encriptar () {
  int semente=0, i=0;
  char texto[1000], textoEncrip[1002], c;
  //nome do arquivo
  char nomeArquivo[100];
  //matriz da playfar
  char matriz[5][5];
  semente = LeituraDaChave ();

  //gerando e imprimindo a matriz
  //printf("PLAYFAR GERADA:\n");
  MatrizMain (semente, matriz);

  //lendo o nome do arquivo
  printf("ENTRE COM O NOME DO ARQUIVO COM O TEXTO A SER ENCRIPTADO: \n");
  scanf("%s", nomeArquivo);

  //arquivo e o texto original e novo e onde vai ser salvo o encriptado
  FILE *arquivo, *novo;

  //abrindo o arquivo
  arquivo = fopen (nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("ERRO NA ABERTURA DO ARQUIVO.\n");
    exit(2);
  }

  //lendo o arquivo
  while ((c = fgetc (arquivo)) != EOF) {
    texto[i] = c;
    i++;
  }
  fclose (arquivo);

  //codificando o arquivo
  CodificaMain(texto, matriz, textoEncrip);

  //salvando o texto codificado para um novo aquivo
  novo = fopen ("TextoEncriptado.txt", "w");
  for (i=0; i < (strlen(textoEncrip)); i++) {
    fputc (textoEncrip[i], novo);
  }
  fclose(novo);

  printf("TEXTO ENCRIPTADO COM SUCESSO NO ARQUIVO: TextoEncriptado.txt.\n");
}

void Desencriptar () {
  int semente=0, i=0;
  char texto[1000], textoDesencrip[1002], c;

  //nome do arquivo
  char nomeArquivo[100];

  //matriz da playfar
  char matriz[5][5];
  semente = LeituraDaChave ();

  //gerando e imprimindo a matriz
  //printf("PLAYFAR GERADA:\n");
  MatrizMain (semente, matriz);

  //lendo o nome do arquivo
  printf("ENTRE COM O NOME DO ARQUIVO COM O TEXTO A SER DESENCRIPTADO: \n");
  scanf("%s", nomeArquivo);

  //arquivo e o texto original e novo e onde vai ser salvo o encriptado
  FILE *arquivo, *novo;

  //abrindo o arquivo
  arquivo = fopen (nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("ERRO NA ABERTURA DO ARQUIVO.\n");
    exit(2);
  }

  //lendo o arquivo
  while ((c = fgetc (arquivo)) != EOF) {
    texto[i] = c;
    i++;
  }
  fclose (arquivo);

  //codificando o arquivo
  DecodificaMain(texto, matriz, textoDesencrip);

  //salvando o texto codificado para um novo aquivo
  novo = fopen ("TextoDesencriptado.txt", "w");
  for (i=0; i < (strlen(textoDesencrip)); i++) {
    fputc (textoDesencrip[i], novo);
  }
  fclose(novo);

  printf("TEXTO DESENCRIPTADO COM SUCESSO NO ARQUIVO: TextoDesencriptado.txt.\n");
}


int LeituraDaChave () {
  //le a chave de encriptacao e chama o codigo que gera a semente
  char chave[201];
  int semente=0;
  printf("ENTRE COM A CHAVE DE ENCRIPTACAO:\n");
  scanf("%s", chave);
  semente = SementeMain (chave);
  //printf("SEMENTE GERADA: %d\n", semente);

  return semente;
}
