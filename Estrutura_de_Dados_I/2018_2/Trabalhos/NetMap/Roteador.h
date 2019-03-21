#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "Terminal.h"

//Tipos Opacos - Estruturas
typedef struct celularoteador Celularoteador;
typedef struct roteador Roteador;
typedef struct listaroteador Listaroteador;

//Funcoes da TAD
Listaroteador* InicializaListaRoteador();
int VerificaListaRoteador(Listaroteador* lr);
Roteador* CriaRoteador(char* nome, char* operadora);
void InsereRoteador(Roteador* rot, Listaroteador* lr);
void RetiraRoteador(Listaroteador* lr, Roteador* rot);
Roteador* ProcuraRoteador(char* nome, Listaroteador* lr);
void RetiraTerminalDoRoteador(Terminal* ter, Roteador* rot);
void VerificaListaTerminalNoRoteador(Roteador* rot);
void InsereTerminalNoRoteador(Roteador* rot, Terminal* ter);
void EnlaceDeRoteador(Roteador* rot1, Roteador* rot2);
void DesfazEnlace(Roteador* rot1, Roteador* rot2);
int RoteadorPorOperadora(char* op, Listaroteador* lr);
void LiberaListaRoteador(Listaroteador* lr);
char* RetornaNomeRoteador(Roteador* rot);
void ImprimeRoteadores(Listaroteador* lr);
Roteador* ProcuraRoteadorPorTerminal(Listaroteador* lr, char* nometer);
void ImprimeTerminaisConectados(char** nomester, Listaroteador* lr, int tam);

#endif
