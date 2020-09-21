#include <stdio.h>
#include <stdlib.h>

 struct aluno {
  char* nome;
  int matricula;
  float p1;
  float p2;
  float p3;
};
typedef struct aluno Aluno;

void Preenche_Turma (Aluno** turma, int tamanho);
void Printa_Turma (Aluno** turma, int tamanho, char letra_turma);
float Media (Aluno* aln);
void imprime_aprovados (int n, Aluno** turma);
float media_turma (int n, Aluno** turma);
void Libera_Turma (int tamanho, Aluno**turma);

int main () {
  int tamanho_T;
  do {
    printf("Qual sera o tamanho da turma?\n");
    scanf("%d", &tamanho_T);
  } while (tamanho_T < 0 || tamanho_T > 10 );
  Aluno** turma = (Aluno**) malloc (tamanho_T * sizeof(Aluno*));
  Preenche_Turma (turma, tamanho_T);
  Printa_Turma (turma, tamanho_T, 'A');
  imprime_aprovados (tamanho_T, turma);
  printf("Media da Turma A: %.2f!\n", media_turma(tamanho_T, turma));

  Libera_Turma (tamanho_T, turma);

  return 0;
}

void Preenche_Turma (Aluno** turma, int tamanho) {
  printf("Hora de entrar com a informacao dos alunos!\n");
  for (int i=0; i < tamanho; i++) {
    turma[i] = (Aluno*) malloc (sizeof (Aluno));
    turma[i]->nome = (char*) malloc (20 * sizeof (char));
    printf("Entre com o nome do aluno %d (tamanho maximo de 20 caracteres):\n", i+1);
    scanf (" %[^\n]", turma[i]->nome);
    printf("Entre com a matricula do aluno %d:\n", i+1);
    scanf("%d", &turma[i]->matricula);
    printf("Entre com a nota da p1 do aluno %d:\n", i+1);
    scanf("%f", &turma[i]->p1);
    printf("Entre com a nota da p2 do aluno %d:\n", i+1);
    scanf("%f", &turma[i]->p2);
    printf("Entre com a nota da p3 do aluno %d:\n", i+1);
    scanf("%f", &turma[i]->p3);

    printf("\n");
  }
}

void Printa_Turma (Aluno** turma, int tamanho, char letra_turma) {
  printf("Turma %c:\n", letra_turma);
  for (int i=0; i < tamanho; i++) {
    printf("Aluno: %s, Matricula: %d\n", turma[i]->nome, turma[i]->matricula);
    printf("Notas: P1 - %.2f, P2 - %.2f, P3 - %.2f;\n", turma[i]->p1, turma[i]->p2, turma[i]->p3);
    printf("\n");
  }
}

float Media (Aluno* aln) {
  float media = (aln->p1 + aln->p2 + aln->p3) / 3;
  return media;
}

void imprime_aprovados (int n, Aluno** turma) {
  printf("Alunos Aprovados:\n");
  for (int i=0; i < n; i++) {
    if (Media(turma[i]) > 5) {
      printf("- %s\n", turma[i]->nome);
    }
  }
  printf("\n");
}

float media_turma (int n, Aluno** turma) {
  float media_total = 0;
  for (int i=0; i < n; i++) {
    media_total += Media(turma[i]);
  }
  return (media_total/n);
}

void Libera_Turma (int tamanho, Aluno**turma) {
  for (int i=0; i < tamanho; i++) {
    free(turma[i]->nome);
    free(turma[i]);
  }
  free(turma);
}
