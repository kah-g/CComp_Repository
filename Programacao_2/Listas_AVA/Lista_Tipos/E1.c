#include <stdio.h>
#include <stdlib.h>

//falta verificar se e bissexto

typedef struct {
  int dia;
  int mes;
  int ano;
} tData;

void VerificaData (tData *data);
void PrintaData (tData *inicial, tData final);
void PassaData (tData *data);

int main () {
  tData inicial, final;
  scanf("%d %d %d", &inicial.dia, &inicial.mes, &inicial.ano);
  scanf("%d %d %d", &final.dia, &final.mes, &final.ano);
  VerificaData (&inicial);
  VerificaData (&final);

  PrintaData(&inicial, final);


  return 0;
}

void VerificaData (tData *data) {
  //verifica se o mes é maior que 12
  if (data->mes > 12) {
    data->mes = 12;
  }
  //verifica se o mes de fevereiro tem mais que 28 dias
  if ((data->mes == 2) && (data->dia > 28)) {
    data->dia = 28;
  }
  //verifica os meses que tem 31 dias
  if ((data->mes == 1 || data->mes == 2 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 1) && (data->dia > 31)) {
    data->dia = 31;
  }
  //verifica os meses que tem 30 dias
  if ((data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) && (data->dia > 30)) {
    data->dia = 30;
  }
}

void PrintaData (tData *inicial, tData final) {
  //tData dataP;
  while ((inicial->dia != final.dia) && (inicial->mes != final.mes) && (inicial->ano != final.ano)) {
    PassaData (inicial);
    printf("%d/%d/%d\n", inicial->dia, inicial->mes, inicial->ano);
  }
}

void PassaData (tData *data) {
  //verifica os dias que tem 31 dias
  if ((data->mes == 1 || data->mes == 2 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 1) && (data->dia < 31)) {
    while (data->dia < 31) {
      data->dia ++;
    }
    if (data->mes < 12) {
      data->dia = 1;
      data->mes++;
    } else {
      data->dia = 1;
      data->mes = 1;
      data->ano++;
    }
  }
  //verifica os dias que tem 30 dias
  if ((data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) && (data->dia < 30)) {
    while (data->dia < 30) {
      data->dia ++;
    }
      data->dia = 1;
      data->mes++;
  }
  //verifica os dias do mes de fevereiro
  if ((data->mes == 2) && (data->dia < 28)) {
    while (data->dia < 28) {
      data->dia ++;
    }
      data->dia = 1;
      data->mes++;
  }
}
