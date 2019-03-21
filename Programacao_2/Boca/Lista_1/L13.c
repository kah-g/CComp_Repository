#include <stdio.h>
#include <stdlib.h>

int main () {
  int nP, nI, q;
  scanf("%d %d", &nP, &nI);
  if (nP == 1) {
    printf("RESP:%d\n", nP);
  } else if (nP > nI) {
    printf("RESP:%d\n", nI);
  } else if (nP == nI) {
    printf("RESP:%d\n", nP);
  } else if (nP < nI) {
    if ((nI % nP) ==  0) {
      printf("RESP:%d\n", nP);
    } else {
      q = nI % nP;
      printf("RESP:%d\n", q);
    }
    }

  return 0;
}
