#include <stdio.h>
#include<stdlib.h>

int main () {
  FILE *p;
  char produto[100];
  float preco, precoT;
  p = fopen("compra.txt", "r");
  if (p == NULL) {
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  //como ler?

  fclose(p);
  return 0;
}
