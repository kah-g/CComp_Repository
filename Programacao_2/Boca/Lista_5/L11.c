#include <stdio.h>
#include <stdlib.h>

void OrdenaCrescente (int *vet, int qtd);
void PercorreVetor (int *vetA, int *vetB, int qtdA, int qtdB, int num, int *A, int *B);
int VerificaRepeticao (int *vet, int qtd, int num);


int main () {
  int qN1, qN2, i;

  //recebendo vetor A
  scanf("%d", &qN1);
  int nums1[qN1];
  for (i=0; i < qN1; i++) {
    scanf("%d", &nums1[i]);
  }

  //recebendo vetor B
  scanf("%d", &qN2);
  int nums2[qN2];
  for (i=0; i < qN2; i++) {
    scanf("%d", &nums2[i]);
  }

  int vetorzao[qN1 + qN2];
  int l=0;
  //copiando vetor A
  for (i=0; i < qN1; i++) {
    vetorzao[l] = nums1[i];
    l++;
  }
  //copiando vetor B
  for (i=0; i < qN2; i++) {
    vetorzao[l] = nums2[i];
    l++;
  }
  //ordenando vetorzao
  OrdenaCrescente (vetorzao, (qN1 + qN2));

  //percorrendo o vetorzao
  char ordem[(qN1 + qN2) + 1];
  int j, k=0;
  int A=0, B=0;
  for (i=0; i < (qN1 + qN2); i++) {
    PercorreVetor (nums1, nums2, qN1, qN2, vetorzao[i], &A, &B);
    if ((A <= 1) && (B <= 1)) {
      if ((A == 1) && (B == 0)) {
        ordem[k] = 'A';
        k++;
      } else if ((A == 0) && (B == 1)) {
        ordem[k] = 'B';
        k++;
      } else if ((A == 1) && (B == 1)) {
        ordem[k] = 'A';
        ordem[k] = 'B';
        k += 2;
      }
    } else {
      if ((A > 1) && (B <= 1)) {
        for (j=0; j < A; j++) {
          ordem[k] = 'A';
          k++;
          i++;
        }
        if (B == 1) {
          ordem[k] = 'B';
          k++;
          i++;
        }
     } else if ((A <= 1) && (B > 1)) {
       if (A == 1) {
         ordem[k] = 'A';
         k++;
         i++;
       }
       for (j=0; j < B; j++) {
         ordem[k] = 'B';
         k++;
         i++;
       }
     } else if ((A > 1) && (B > 1)) {
       for (j=0; j < A; j++) {
         ordem[k] = 'A';
         k++;
         i++;
       }
       for (j=0; j < B; j++) {
         ordem[k] = 'B';
         k++;
         i++;
       }
     }
    }
  }
  ordem[k] = '\0';

  printf("%s\n", ordem);

  return 0;
}

void OrdenaCrescente (int *vet, int qtd) {
  int i, aux, j;
  //i percorre o elemento pelo vetor
  //j percorre o vetor todo

  for (j=0; j < qtd; j++) {
    for (i=0; i < ((qtd - j) - 1); i++) {
      if (vet[i] > vet[i+1]) {
        aux = vet[i];
        vet[i] = vet[i+1];
        vet[i+1] = aux;
      }
    }
  }
}

void PercorreVetor (int *vetA, int *vetB, int qtdA, int qtdB, int num, int *A, int *B) {
  int i, repetido;
  //verificando em A
  for (i=0; i < qtdA; i++) {
    if (num == vetA[i]) {
      repetido = VerificaRepeticao (vetA, qtdA, num);
      if (repetido > 1) {
        *A = repetido;
        break;
      } else {
        *A = 1;
        break;
      }
    }
  }
  //verificando em B
  for (i=0; i < qtdB; i++) {
    if (num == vetB[i]) {
      repetido = VerificaRepeticao (vetB, qtdB, num);
      if (repetido > 1) {
        *B = repetido;
        break;
      } else {
        *B = 1;
        break;
      }
    }
  }
}

int VerificaRepeticao (int *vet, int qtd, int num) {
  int i, c=0;
  for (i=0; i < qtd; i++) {
    if (vet[i] == num) {
      c++;
    }
  }

  return c;
}
