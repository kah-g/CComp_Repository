#include <stdio.h>
#include <stdlib.h>

int main () {
  int nums1, nums2, menor=3200, contI=0, contF=0, cont=0,veri=0;
  while ((scanf("%d", &nums1)) == 1) {
    if (nums1 < menor) {
      menor = nums1;
    }
  }
  setbuf (stdin,NULL);
  while ((scanf("%d", &nums2)) == 1) {
   if ((contI == 0) && (veri == 0)) {
      if (nums2 == menor) {
        contI = cont;
        veri = 1;
      }
    } else {
      if (nums2 == menor) {
        contF = cont;
      }
    }
      cont++;
  }
  if (((contI == 0) && (contF == 0)) && (veri == 0)) {
    contI = cont;
    contF = cont;
  }
  if ((contI != 0) && (contF == 0)) {
    contF = contI;
  }
  printf("%d %d %d\n", menor, contI, contF);

  return 0;
}
