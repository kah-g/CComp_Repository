#include "GeraSemente.h"

int SementeMain (char *senha) {
  int semente=0;
  if ((senha[0] >= 'A') && (senha[0] <= 'Z')) {
    //converte com os valores de letra maiuscula
    semente = ConverteMaiuscula (senha);
  } else if ((senha[0] >= 'a') && (senha[0] <= 'z')) {
    //converte com os valores de letra minuscula
    semente = ConverteMinuscula (senha);
  } else if ((senha[0] >= '0') && (senha[0]) <= '9') {
    //converte com os valores de numeros
    semente = ConverteNumero (senha);
  }

  return semente;
  //retorna a semente
}

int ConverteMaiuscula (char *senha) {
  //vai converter a senha quando o primeiro caractere e uma letra maiuscula
  //le a quantidade de cada tipo de caractere para gerar a semente
  int tamanho=0, semente=0;
  int maiuscula=0, minuscula=0, numeros=0;
  tamanho = strlen (senha);
  LeQuantidades (senha, tamanho, &maiuscula, &minuscula, &numeros);
  if (minuscula == 0) {
    //caso a quantidade de minusculas seja 0
    semente = ((maiuscula * 8) * (1 * 1)) - (numeros * 7);
  } else {
    semente = ((maiuscula * 8) * (minuscula * 4)) - (numeros * 7);
  }

  return semente;
}

int ConverteMinuscula (char *senha) {
  //vai converter a senha quando o primeiro caractere e uma letra minuscula
  int tamanho=0, semente=0;
  int maiuscula=0, minuscula=0, numeros=0;
  tamanho = strlen (senha);
  LeQuantidades (senha, tamanho, &maiuscula, &minuscula, &numeros);
  if (maiuscula == 0) {
    //caso a quantidade de maiusculas seja 0
    semente = ((1 * 1) * (minuscula * 6)) - (numeros * 5);
  } else {
    semente = ((maiuscula * 3) * (minuscula * 6)) - (numeros * 5);
  }

  return semente;
}

int ConverteNumero (char *senha){
  //vai converter a senha quando o primeiro caractere e um numero
  int tamanho=0, semente=0;
  int maiuscula=0, minuscula=0, numeros=0;
  tamanho = strlen (senha);
  LeQuantidades (senha, tamanho, &maiuscula, &minuscula, &numeros);
  if (maiuscula == 0) {
    //caso o numero de maiusculas seja 0
    semente = ((1 * 1) * (minuscula * 2)) - (numeros * 11);
  } else if (minuscula == 0) {
    //caso o numero de minusculas seja 0
    semente = ((maiuscula * 9) * (1 * 2)) - (numeros * 11);
  } else {
    semente = ((maiuscula * 9) * (minuscula * 2)) - (numeros * 11);
  }

  return semente;
}

void LeQuantidades (char *senha, int tamanho, int *maiuscula, int *minuscula, int *numeros) {
  int i;
  for (i=0; i < tamanho; i++) {
    if ((senha[i] >= 'A') && (senha[i] <= 'Z')) {
      *maiuscula += 1;
    } else if ((senha[i] >= 'a') && (senha[i] <= 'z')) {
      *minuscula += 1;
    } else if ((senha[i] >= '0') && (senha[i]) <= '9') {
      *numeros += 1;
    }
  }
}
