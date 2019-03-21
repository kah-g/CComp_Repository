#ifndef TERMINAL_H
#define TERMINAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo Opaco - Estruturas
typedef struct celulaterminal Celulaterminal;
typedef struct terminal Terminal;
typedef struct listaterminal Listaterminal;

//Funcoes da TAD
Listaterminal* InicializaListaTerminal();
int VerificaListaTerminal(Listaterminal* lt);
Terminal* CriaTerminal(char* nome, char* local);
void InsereTerminal(Terminal* ter, Listaterminal* lt);
Celulaterminal* RetiraTerminal(Listaterminal* lt, Terminal* ter);
int RetiraRoteadorDoTerminal(Terminal* ter);
Terminal* ProcuraTerminal(char* nome, Listaterminal* lt);
void ConectaRoteadorAoTerminal(Terminal* ter);
void DesconectaTerminalNaListaDeRoteadores(Listaterminal* lt);
int TerminalPorLocal(char* local, Listaterminal* lt);
void LiberaTerminal(Celulaterminal* cllter);
void LiberaListaTerminal(Listaterminal* lt);
char** ImprimeTerminais(Listaterminal* lt, int* ind);
int TamanhoListaTerminal(Listaterminal* lt);

#endif
