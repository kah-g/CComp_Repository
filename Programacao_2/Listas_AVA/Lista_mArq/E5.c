#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char nome[20];
  char telefone[12];
  int diaB;
  int mesB;
} contato;

void AddContato ();
void LeContato ();

int main () {
  int op;
  printf("Bem vindo a sua agenda digital. Escolha uma das opções abaixo:\n");
  printf("1-Adicionar Contato\n2-Remover Contato\n3-Pesquisar Contato\n4-Listar Contatos\n5-Listar Contatos por Letra\n6-Imprimir Aniversariantes\n7-Sair\n");

  scanf("%d", &op);
  switch (op) {
    case 1:
     AddContato();
     //adicionar contato
     break;
    case 2:
     //remover contato
     break;
    case 3:
     //pesquisar contato
     break;
    case 4:
    LeContato();
     //listar contatos
     break;
    case 5:
     //listar contatos por Letra
     break;
    case 6:
     //imprimir aniversariantes do mes
     break;
    case 7:
     //sair
     exit(1);
    default:
     printf("Opcao invalida\n");
     exit(1);
  }

  return 0;
}

void AddContato () {
  FILE *ag;
  ag = fopen ("agenda.bin", "ab");
  contato ct1;
  printf("Entre com os dados do contato.\n");
  scanf("%s", ct1.nome);
  scanf("%s", ct1.telefone);
  scanf("%d %d", &ct1.diaB, &ct1.mesB);
  //fwrite (&ct1, sizeof(contato), 1, ag);
  if ((fwrite (&ct1, sizeof(contato), 1, ag)) == 1) {
    printf("Contato adicionado com sucesso.\n");
  } else {
    printf("Ocorreu algum erro ao adicionar o arquivo. Tente novamente mais tarde\n");
  }
  fclose(ag);
}

void LeContato () {
  FILE *ag;
  int i=0,c=0;
  contato ctAg[100];
  ag = fopen ("agenda.bin", "rb");
  fseek (ag, sizeof (contato), SEEK_SET);
  while (1) {
    fread (&ctAg[i], sizeof(contato), 1, ag);
    if (feof(ag)) {
      break;
    }
    i++;
    c++;
  }
  fseek (ag, sizeof (contato), SEEK_SET);
  printf("Tamanho da agenda: %d\n", c);

  fclose(ag);
}
