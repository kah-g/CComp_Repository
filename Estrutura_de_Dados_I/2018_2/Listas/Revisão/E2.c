#include <stdio.h>
#include <stdlib.h>

void ModificaValor (int* ponteiro);

int main () {
  //criar 4 variaveis do tipo inteiro e 4 do tipo ponteiro para inteiro
  //manipular as variaveis do tipo inteiro atraves dos tipos ponteiros

  //criando as variaveis
  int a, b, c, d;
  int* pa;
  int* pb;
  int* pc;
  int* pd;
  char op;

  //lendo valores para as variaveis
  printf("Entre com os valores dos inteiros:\n");
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);

  //assimilando os ponteiros para as variaveis
  pa = &a;
  pb = &b;
  pc = &c;
  pd = &d;

  //usando a funcao modifica valor
  printf("De qual variavel deseja alterar o valor?\nAs opcoes sao A, B, C e D.\n");
  setbuf(stdin,NULL);
  scanf("%c", &op);
  if ((op == 'a') || (op == 'b') || (op == 'c') || (op == 'd')) {
    op = ('A' + (op - 'a'));
  }
  switch (op) {
    case 'A':
      ModificaValor (pa);
      printf("Novo valor de A: %d\n", a);
      break;
    case 'B':
      ModificaValor (pb);
      printf("Novo valor de B: %d\n", b);
      break;
    case 'C':
      ModificaValor (pc);
      printf("Novo valor de C: %d\n", c);
      break;
    case 'D':
      ModificaValor (pd);
      printf("Novo valor de D: %d\n", d);
      break;
    default:
      printf("Essa opcao nao existe.\n");
      break;
  }


  return 0;
}

void ModificaValor (int* ponteiro) {
  int n;
  printf("Entre com o novo valor:\n");
  scanf("%d", &n);
  *ponteiro = n;
}
