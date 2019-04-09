#include "jogo.h"

int main () {
  Menu ();
  return 0;
}

/* Teste para baralho.c
#include "baralho.h"

int main () {
  printf("Que comecem os teste: \n");
  Baralho *brl = InicializaBaralho();
  printf("\nBaralho Original:\n\n");
  PrintaBaralho(brl);
  Baralho *brlE = EmbaralharBaralho(brl);
  printf("\nBaralho Embaralhado:\n\n");
  PrintaBaralho(brlE);
  Carta* trunfo = CortaBaralho (brlE);
  printf("\nBaralho Cortado\n\n");
  PrintaCarta(trunfo);
  PrintaBaralho(brlE);
}
*/
