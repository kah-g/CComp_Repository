#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include "matriz.h"

//Estruturas
typedef struct celulamatriz Celulamatriz;
typedef struct listamatriz Listamatriz;

//funcoes da tad
Listamatriz* inicializalista ();
void inserematriz (Listamatriz* lmat, Matriz* mat);
Matriz* retiramatriz (Listamatriz* lmat, int posicao);
void imprimelista (Listamatriz* lmat);
void liberacelula (Celulamatriz* celmat);
void liberalista (Listamatriz* lmat);

#endif
