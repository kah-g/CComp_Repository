#ifndef NETMAP_H
#define NETMAP_H

#include "Roteador.h"

void CadastraRoteador(char* nome, char* operadora, Listaroteador* lr);
void CadastraTerminal(char* nome, char* local, Listaterminal* lt);
void RemoveRoteador(char* nome, Listaroteador* lr);
void ConectaTerminal(char* nometer, char* nomerot, Listaterminal* lt, Listaroteador* lr);
void DesconectaTerminal(char* nometer, Listaterminal* lt, Listaroteador* lr);
void RemoveTerminal(char* nometer, Listaterminal* lt, Listaroteador* lr);
void ConectaRoteadores(char* nomerot1, char* nomerot2, Listaroteador* lr);
void DesconectaRoteadores(char* nomerot1, char* nomerot2, Listaroteador* lr);
void FrequenciaTerminal(char* local, Listaterminal* lt);
void FrequenciaOperadora(char* operadora, Listaroteador* lr);
void ImprimeNetMap(Listaterminal* lt, Listaroteador* lr, int contador);

#endif
