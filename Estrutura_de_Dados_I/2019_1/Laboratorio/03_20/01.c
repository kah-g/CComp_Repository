#include <stdio.h>
#include <stdlib.h>

int main () {
  int num;
  char letra;
  float real;
  printf("Entre com um valor inteiro.\n");
  scanf("%d", &num);
  printf("Entre com uma letra.\n");
  //letra = getchar();
  scanf(" %c", &letra);
  printf("Entre com um valor real.\n");
  scanf("%f", &real);
  int *numP = &num;
  char *letraP = &letra;
  float *realP = &real;
  printf("\n");
  printf("Valores antes da modificação:\nint: %d\nchar: %c\nreal: %f\n", num, letra, real);
  printf("\n");
  *numP *= 5;
  *letraP += 5;
  *realP += 5.5;
  printf("Valores apos a modificação:\nint: %d\nchar: %c\nreal; %f\n", *numP, *letraP, *realP);

  return 0;
}
