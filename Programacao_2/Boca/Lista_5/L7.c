#include <stdio.h>
#include <stdlib.h>

int razao (int n, int n1);
int pa (int razao, int qNums, int *nums);

int main () {
  int qNums, i, r;
  scanf("%d", &qNums);

  //lendo o vetor
  int nums[qNums];
  for (i=0; i < qNums; i++) {
    scanf("%d", &nums[i]);
  }

  i = 0;
  if (qNums == 1) {
    printf("NAO\n");
  } else {
    if ((nums[i] < nums[i+1]) || (nums[i] == nums[i+1])) {
      //ordem crescente
      r = razao (nums[i+1], nums[i]);
      if ((pa (r, qNums, nums)) == 0) {
        printf("NAO\n");
      } else if ((pa (r, qNums, nums)) == 1) {
        printf("RESP:%d\n", r);
      }
    } else if (nums[i] > nums[i+1]) {
      //ordem decrescente
      r = razao (nums[i], nums[i+1]);
      r = r * (-1);
      if ((pa (r, qNums, nums)) == 0) {
        printf("NAO\n");
      } else if ((pa (r, qNums, nums)) == 1) {
        printf("RESP:%d\n", r);
      }
    }
  }

  return 0;
}

int razao (int n, int n1) {
  //n e o maior numero e n1 o menor
  return (n - n1);
}

int pa (int razao, int qNums, int *nums) {
  int i;
  for (i=0; i < (qNums - 1);) {
    if ((nums[i+1] - nums[i]) == razao) {
      i++;
    } else {
      //retorna 0 se nao e pa
      return 0;
    }
  }
  //retorna 1 se e pa
  return 1;
}
