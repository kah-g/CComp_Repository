//--------------- Programa Testador ---------------

#include "NetMap.h"

int main (int argc, char const** argv) {
  //inicializando a lista de terminais
  Listaterminal* netmapT = InicializaListaTerminal();

  //inicializando a lista de roteadores
  Listaroteador* netmapR = InicializaListaRoteador();

  //a partir daqui ler o arquivo txt
  //arqE e o arquivo de entrada
  FILE *arqET;
  arqET = fopen(argv[1], "r");
  if (arqET == NULL) {
    fprintf(arqET, "Erro: O arquivo entrada.txt nao existe.\n");
    fclose(arqET);
    return 0;
  }

  //lendo o arquivo
  char* comando = (char*)malloc(sizeof(char)*40);
  char nome[30];
  char operadora[30];
  char local[30];
  char nometer[30];
  char nomerot[30];
  char nomerot1[30];
  char nomerot2[30];
  int contadorimprime = 0;
  while (!feof(arqET)) {
  	fscanf(arqET, "%s", comando);
    printf("%s\n", comando);
    if(!strcmp(comando, "CADASTRAROTEADOR")) {
      fscanf(arqET, "%s %s\n", nome, operadora);
      CadastraRoteador(nome, operadora, netmapR);
    }
    if(!strcmp(comando, "CADASTRATERMINAL")) {
      fscanf(arqET, "%s %s\n", nome, local);
      CadastraTerminal(nome, local, netmapT);
    }
    if(!strcmp(comando, "REMOVEROTEADOR")) {
      fscanf(arqET, "%s\n", nome);
      RemoveRoteador(nome, netmapR);
    }
    if(!strcmp(comando, "CONECTATERMINAL")) {
      fscanf(arqET, "%s %s\n", nometer, nomerot);
      ConectaTerminal(nometer, nomerot, netmapT, netmapR);
    }
    if(!strcmp(comando, "DESCONECTATERMINAL")) {
      fscanf(arqET, "%s\n", nome);
      DesconectaTerminal(nome, netmapT, netmapR);
    }
    if(!strcmp(comando, "REMOVETERMINAL")) {
      fscanf(arqET, "%s\n", nome);
      RemoveTerminal(nome, netmapT, netmapR);
    }
    if(!strcmp(comando, "CONECTAROTEADORES")) {
      fscanf(arqET, "%s %s\n", nomerot1, nomerot2);
      ConectaRoteadores(nomerot1, nomerot2, netmapR);
    }
    if(!strcmp(comando, "DESCONECTAROTEADORES")) {
      fscanf(arqET, "%s %s\n", nomerot1, nomerot2);
      DesconectaRoteadores(nomerot1, nomerot2, netmapR);
    }
    if(!strcmp(comando, "FREQUENCIATERMINAL")) {
      fscanf(arqET, "%s\n", local);
      FrequenciaTerminal(local, netmapT);
    }
    if(!strcmp(comando, "FREQUENCIAOPERADORA")) {
      fscanf(arqET, "%s\n", operadora);
      FrequenciaOperadora(operadora, netmapR);
    }
    if(!strcmp(comando, "IMPRIMENETMAP")) {
      ImprimeNetMap(netmapT, netmapR, contadorimprime);
      contadorimprime++;
    }
    if(!strcmp(comando, "FIM")) {
      LiberaListaRoteador(netmapR);
      LiberaListaTerminal(netmapT);
      break;
    }
  }

  fclose(arqET);
  return 0;
}
