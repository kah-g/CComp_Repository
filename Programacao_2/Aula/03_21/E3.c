#include <stdio.h>
#include <stdlib.h>

int main () {
  int nota,notaPf,notaMedia;
  printf("Entre com a nota \n");
  scanf("%d", &nota);
  if (nota <70) {
    printf("O aluno ficou de prova final\n");
    printf("Entre com a nota da prova final\n");
    scanf("%d", &notaPf);
    notaMedia = (notaPf + nota) /2;
    if (notaMedia >= 50) {
      printf("O aluno foi aprovado na prova final\n");
    }
    else {
      printf("O aluno não foi aprovado na prova final\n");
    }
  }
  else {
    printf("O aluno foi aprovado direto\n");
  }

  return 0;
}
