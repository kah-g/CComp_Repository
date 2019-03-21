#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InverteString (char* original, char* invertido);

int main () {
  //ler uma string e a inverter
  printf("Entre com a string:\n");
  char* palavra = (char*)malloc(sizeof(char)*21);
  char* invPalavra = (char*)malloc(sizeof(char)*21);
  scanf("%s", palavra);
  InverteString (palavra, invPalavra);
  printf("String invertida: %s.\n", invPalavra);
  free (palavra);
  free(invPalavra);

  return 0;
}

void InverteString (char* original, char* invertido) {
  int tamanho, t, i;
  tamanho = strlen (original);
  t = tamanho - 1;
  for (i=0; i < tamanho; i++) {
    invertido[i] = original[t];
    t--;
  }
  i++;
  invertido[i] = '\0';
}
