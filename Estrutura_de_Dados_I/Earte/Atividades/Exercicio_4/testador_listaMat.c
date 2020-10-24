//testados do tad lista
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listamat.h"

int main() {
  srand(time(NULL));

  //criando, preenchendo e imprimindo mat1
  printf("----- Matriz 1 -----\n");
  Matriz* mat1;
  mat1 = inicializaMatriz (2,2);
  for (int i=0;i<2;i++) {
    for (int j=0;j<2; j++) {
      modificaElemento(mat1, i, j, rand() %100);
    }
  }
  imprimeMatriz(mat1);

  //criando, preenchendo e imprimindo mat2
  printf("----- Matriz 2 -----\n");
  Matriz* mat2;
  mat2 = inicializaMatriz (2,2);
  for (int i=0;i<2;i++) {
    for (int j=0;j<2; j++) {
      modificaElemento(mat2, i, j, rand() %100);
    }
  }
  imprimeMatriz(mat2);

  //criando, preenchendo e imprimindo mat3
  printf("----- Matriz 3 -----\n");
  Matriz* mat3;
  mat3 = inicializaMatriz (3,4);
  for (int i=0;i<3;i++) {
    for (int j=0;j<4; j++) {
      modificaElemento(mat3, i, j, rand() %100);
    }
  }
  imprimeMatriz(mat3);

  //criando, preenchendo e imprimindo mat4
  printf("----- Matriz 4 -----\n");
  Matriz* mat4;
  mat4 = inicializaMatriz (4,7);
  for (int i=0;i<4;i++) {
    for (int j=0;j<7; j++) {
      modificaElemento(mat4, i, j, rand() %100);
    }
  }
  imprimeMatriz(mat4);

  //criando lista encadeada
  Listamatriz* lt01 = inicializalista();

  //preenchendo a lista01
  inserematriz (lt01, mat1);
  inserematriz (lt01, mat2);
  inserematriz (lt01, mat3);
  inserematriz (lt01, mat4);

  //criando outra lista encadeada
  Listamatriz* lt02 = inicializalista();

  //preenchendo a lista com a transposta de cada matriz
  inserematriz (lt02, transposta(mat1));
  inserematriz (lt02, transposta(mat2));
  inserematriz (lt02, transposta(mat3));
  inserematriz (lt02, transposta(mat4));


  //imprimindo as listas
  imprimelista (lt01);
  imprimelista (lt02);

  //retirando das listas
  Matriz* m01 = retiramatriz (lt01, 1);
  Matriz* m02 =retiramatriz (lt01, 3);
  imprimelista (lt01);

  Matriz* m03 =retiramatriz (lt02, 2);
  imprimelista (lt02);

  //inserindo novamente as matrizes
  inserematriz (lt01, m01);
  inserematriz (lt01, m02);
  imprimelista (lt01);
  inserematriz (lt02, m03);
  imprimelista (lt02);

  //destruindo lista
  liberalista (lt01);
  liberalista (lt02);

}
