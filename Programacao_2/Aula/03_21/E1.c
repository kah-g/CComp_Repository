#include <stdio.h>
#include <stdlib.h>

int main () {
  int nota;
  printf("Entre com a nota \n");
  scanf("%d", &nota);
  if (nota >=30 && nota <70) {
    printf("O aluno precisa fazer prova final\n");
  }

  return 0;
}
