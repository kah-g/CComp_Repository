#include <stdio.h>
#include <stdlib.h>

int Comparador (int altura1, int altura2);

int main () {
  //j e k percorrem o vetor a ser preenchidos com os postes
  //qPostes e a quantidade de postes
  //p percorre o vetor para printar
  int qPostes, i, maior=-1, j=0, k=0, p;
  scanf("%d", &qPostes);
  //alturaPoste e o vetor com a altura dos postes
  int alturaPoste[qPostes], paresAltura[qPostes][2];
  for (i=0; i < qPostes; i++) {
    scanf("%d", &alturaPoste[i]);
  }

  if (qPostes == 1) {
    printf("IMPOSSIVEL\n");
  } else {
    for (i=0; i < (qPostes - 1); i++) {
      if ((Comparador (alturaPoste[i], alturaPoste[i+1])) > maior) {
        maior = Comparador (alturaPoste[i], alturaPoste[i+1]);
        j = 0;
        paresAltura[j][k] = i;
        paresAltura[j][k+1] = i+1;
      } else if ((Comparador (alturaPoste[i], alturaPoste[i+1])) == maior) {
        j++;
        paresAltura[j][k] = i;
        paresAltura[j][k+1] = i+1;
      }
    }
  }

  //printando o vetor
  if (qPostes > 1) {
    if (j == 0) {
      p = 1;
    } else {
      p = j + 1;
    }
  } else {
    p = j;
  }

  j = 0;

  for (i=0; i < p; i++) {
    printf("(%d %d) ", paresAltura[j][k], paresAltura[j][k+1]);
    j++;
  }
  //printf("\n");

  return 0;
}

int Comparador (int altura1, int altura2) {
  if (altura1 > altura2) {
    //se a primeira e maior que a segunda
    return (altura1 - altura2);
  } else if (altura2 > altura1) {
    //se a segunda e maior que a primeira
    return (altura2 - altura1);
  } else {
    //se sao iguais
    return 0;
  }
}
