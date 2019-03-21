#include <stdio.h>
#include <stdlib.h>

int VerificaDigito (char c);
char VerificaMaiuscula (char d);
int Comprimento (char* palavra);
void CopiaString (char* destino, char* origem);
int Compara (char* palavraA, char* palavraB);

int main () {
  //varios pequenos exercicios

  //variaveis
  int q, r, t, s;
  char c, d, e;

  //malloc's
  char* palavra = (char*)malloc(sizeof(char)*21);
  char* palavraC = (char*)malloc(sizeof(char)*22);

  printf("Entre com o numero do exercicio.\n");
  scanf("%d", &q);
  switch (q) {
    case 1:
      //verifica se o caractere e um digito
      printf("Entre com o caractere:\n");
      scanf("%c", &c);
      r = VerificaDigito(c);
      if (r == 1) {
        printf("E um digito\n");
      } else {
        printf("Nao e um digito\n");
      }
      break;
    case 2:
      //retorna um caractere maiusculo se a entrada for um caractere minusculo
      //ser for maisculo retorna ele mesmo, se for digito nao retorna nada
      printf("Entre com o caractere:\n");
      scanf("%c", &d);
      e = VerificaMaiuscula (d);
      if ((e >= 'A') && (e <= 'Z')) {
        if ((d >= 'A') && (d <= 'Z')) {
          printf("O caractere ja era maiusculo: %c\n", e);
        } else {
          printf("O caractere minusculo foi trocado pelo maiusculo: %c\n", e);
        }
      } else {
        printf("O caractere nao era uma letra\n");
      }
      break;
    case 3:
      //implemente o strlen
      printf("Entre com a string:\n");
      scanf("%s", palavra);
      t = Comprimento(palavra);
      printf("O tamanho da string é: %d\n", t);
      free(palavra);
      break;
    case 4:
      //implemente o strcpy - funcao que copia strings
      printf("Entre com a string:\n");
      scanf("%s", palavra);
      CopiaString(palavraC, palavra);
      printf("String copiada: %s\n", palavraC);
      free(palavra);
      free(palavraC);
      break;
    case 5:
      //implementa a strcmp - funcao que compara strings
      printf("Entre com a primeira string:\n");
      scanf("%s", palavra);
      printf("Entre com a segunda string:\n");
      scanf("%s", palavraC);
      s = Compara(palavra, palavraC);
      if (s == 1) {
        printf("As string sao iguais\n");
      } else if (s == 2) {
        printf("Uma palavra esta inteiramente contida na outra.\n");
      } else {
        printf("As strings sao diferentes\n");
      }
      free (palavra);
      free(palavraC);
      break;
    default:
      printf("Essa opcao nao existe.\n");
      break;
  }

  return 0;
}

int VerificaDigito (char c) {
  if ((c >= '0') && (c <= '9')) {
    return 1;
  } else {
    return 0;
  }
}

char VerificaMaiuscula (char d) {
  if ((d >= 'A') && (d <= 'Z')) {
    return d;
  } else if ((d >= 'a') && (d <= 'z')) {
    return ('A' + (d - 'a'));
  } else {
    return '0';
  }
}

int Comprimento (char* palavra) {
  int tamanho=0, i;
  for (i = 0;; i++) {
    if (palavra[i] == '\0') {
      break;
    } else {
      tamanho++;
    }
  }
  return tamanho;
}

void CopiaString (char* destino, char* origem) {
  int i;
  for (i = 0;; i++) {
    if (origem[i] == '\0') {
      break;
    } else {
      destino[i] = origem[i];
    }
  }
  destino[i] = '\0';
}

int Compara (char* palavraA, char* palavraB) {
  int tamanhoA, tamanhoB, i, menor;

  //verifica o tamanho das string e separa o tamanho da menor se houver
  tamanhoA = Comprimento(palavraA);
  tamanhoB = Comprimento(palavraB);
  if (tamanhoA > tamanhoB) {
    menor = tamanhoB;
  } else if (tamanhoB > tamanhoA) {
    menor = tamanhoA;
  } else {
    menor = tamanhoA;
  }

  //percorre as duas string as comparando
  for (i=0; i < menor; i++) {
    if (palavraA[i] != palavraB[i]) {
      break;
    }
  }

  //retorna 1 se forem iguais, 2 se uma palavra estiver contida na outra por completo
  //retorna 0 se forem diferentes
  if ((tamanhoA > tamanhoB) || (tamanhoB > tamanhoA)) {
    if (i == menor) {
      return 2;
    } else {
      return 0;
    }
  } else {
    if (i == menor) {
      return 1;
    } else {
      return 0;
    }
  }
}
