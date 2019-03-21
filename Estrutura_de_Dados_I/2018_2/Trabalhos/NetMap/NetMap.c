#include "NetMap.h"

void CadastraRoteador(char* nome, char* operadora, Listaroteador* lr) {
  if(VerificaListaRoteador(lr) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de roteadores não existe.\n\n");
    fclose(arqE);
    return;
  }
  Roteador* rot = CriaRoteador(nome, operadora);
  InsereRoteador(rot, lr);
}

void CadastraTerminal(char* nome, char* local, Listaterminal* lt) {
  if(VerificaListaTerminal(lt) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de terminais não existe.\n\n");
    fclose(arqE);
    return;
  }
  Terminal* ter = CriaTerminal(nome, local);
  InsereTerminal(ter, lt);
}

void RemoveRoteador(char*nome, Listaroteador* lr) {
  if(VerificaListaRoteador(lr) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de roteadores não existe.\n\n");
    fclose(arqE);
    return;
  }
  Roteador* rot = ProcuraRoteador(nome, lr);
  if(rot == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O roteador %s não pertence a lista.\n\n", nome);
    fclose(arqE);
    return;
  }
  RetiraRoteador(lr, rot);
}

void ConectaTerminal(char* nometer, char* nomerot, Listaterminal* lt, Listaroteador* lr) {
  if(VerificaListaTerminal(lt) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de terminais não existe.\n\n");
    fclose(arqE);
    return;
  }
  if(VerificaListaRoteador(lr) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de roteadores não existe.\n\n");
    fclose(arqE);
    return;
  }
  Terminal* ter = ProcuraTerminal(nometer, lt);
  Roteador* rot = ProcuraRoteador(nomerot, lr);
  if(rot == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O roteador %s não pertence a lista.\n\n", nomerot);
    fclose(arqE);
    return;
  }
  if(ter == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O terminal %s não pertence a lista.\n\n", nometer);
    fclose(arqE);
    return;
  }
VerificaListaTerminalNoRoteador(rot);
InsereTerminalNoRoteador(rot, ter);
ConectaRoteadorAoTerminal(ter);
}

void DesconectaTerminal(char* nometer, Listaterminal* lt, Listaroteador* lr) {
  if(VerificaListaTerminal(lt) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de terminais não existe.\n\n");
    fclose(arqE);
    return;
  }
  Terminal* ter = ProcuraTerminal(nometer, lt);
  if(ter == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O terminal %s não pertence a lista.\n\n", nometer);
    fclose(arqE);
    return;
  }
  Roteador* rot = ProcuraRoteadorPorTerminal(lr, nometer);
  if(rot == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O terminal %s esta conectado a nenhum roteador.\n\n", nometer);
    fclose(arqE);
    return;
  }
  RetiraTerminalDoRoteador(ter, rot);
  RetiraRoteadorDoTerminal(ter);
}

void RemoveTerminal(char* nometer, Listaterminal* lt, Listaroteador* lr) {
  if(VerificaListaTerminal(lt) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de terminais não existe.\n\n");
    fclose(arqE);
    return;
  }
  Terminal* ter = ProcuraTerminal(nometer, lt);
  if(ter == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O terminal %s não pertence a lista.\n\n", nometer);
    fclose(arqE);
    return;
  }
  if(RetiraRoteadorDoTerminal(ter)) {
    Roteador* rot = ProcuraRoteadorPorTerminal(lr, nometer);
    RetiraTerminalDoRoteador(ter, rot);
  }
  Celulaterminal* cllter = RetiraTerminal(lt, ter);
  LiberaTerminal(cllter);

}

void ConectaRoteadores(char* nomerot1, char* nomerot2, Listaroteador* lr) {
  if(VerificaListaRoteador(lr) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de roteadores não existe.\n\n");
    fclose(arqE);
    return;
  }
  Roteador* rot1 = ProcuraRoteador(nomerot1, lr);
  Roteador* rot2 = ProcuraRoteador(nomerot2, lr);
  if(rot1 == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O roteador %s não pertence a lista.\n\n", nomerot1);
    fclose(arqE);
  }
  if(rot2 == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O roteador %s não pertence a lista.\n\n", nomerot2);
    fclose(arqE);
    return;
  }
  EnlaceDeRoteador(rot1, rot2);
}

void DesconectaRoteadores(char* nomerot1, char* nomerot2, Listaroteador* lr) {
  if(VerificaListaRoteador(lr) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de roteadores não existe.\n\n");
    fclose(arqE);
    return;
  }
  Roteador* rot1 = ProcuraRoteador(nomerot1, lr);
  Roteador* rot2 = ProcuraRoteador(nomerot2, lr);
  if(rot1 == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O roteador %s não pertence a lista.\n\n", nomerot1);
    fclose(arqE);
    return;
  }
  if(rot2 == NULL) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: O roteador %s não pertence a lista.\n\n", nomerot2);
    fclose(arqE);
    return;
  }
  DesfazEnlace(rot1, rot2);
}

void FrequenciaTerminal(char* local, Listaterminal* lt) {
  if(VerificaListaTerminal(lt) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de terminais não existe.\n\n");
    fclose(arqE);
    return;
  }
  int num = TerminalPorLocal(local, lt);
  FILE *arqS;
  arqS = fopen ("saida.txt", "a");
  fprintf(arqS, "FREQUENCIATERMINAL %s: %d.\n\n", local, num);
  fclose(arqS);
}

void FrequenciaOperadora(char* operadora, Listaroteador* lr) {
  if(VerificaListaRoteador(lr) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de roteadores não existe.\n\n");
    fclose(arqE);
    return;
  }
  int num = RoteadorPorOperadora(operadora, lr);
  FILE *arqS;
  arqS = fopen ("saida.txt", "a");
  fprintf(arqS, "FREQUENCIAROTEADOR %s: %d.\n\n", operadora, num);
  fclose(arqS);
}

void ImprimeNetMap(Listaterminal* lt, Listaroteador* lr, int contador) {
  if(VerificaListaTerminal(lt) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de terminais não existe.\n\n");
    fclose(arqE);
    return;
  }
  if(VerificaListaRoteador(lr) == 0) {
    FILE *arqE;
    arqE = fopen ("log.txt", "a");
    fprintf(arqE, "Erro: A lista de roteadores não existe.\n\n");
    fclose(arqE);
    return;
  }
  FILE *arqSd;
  arqSd = fopen("saida.dot", "a");
  if(contador > 0) {
    fprintf(arqSd, "//intermediario\n\n");
  }
  fprintf(arqSd, "strict graph {\n");
  fclose(arqSd);
  int tamanho = 0;
  char** terminaisconectados = ImprimeTerminais(lt, &tamanho);
  if(terminaisconectados != NULL) {
    ImprimeTerminaisConectados(terminaisconectados, lr, tamanho);
  }
  ImprimeRoteadores(lr);
  arqSd = fopen("saida.dot", "a");
  fprintf(arqSd, "}\n");
  for(int i=0; i < tamanho; i++) {
    free(terminaisconectados[i]);
  }
  free(terminaisconectados);
  fclose(arqSd);
}
