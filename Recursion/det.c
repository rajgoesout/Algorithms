#include <stdio.h>
#include <math.h>

int det(int a[][], int n){
  if (n == 1)
    return a[0][0];
  else {
    int i=0, p=0;
    for (j = 0; j < n; j++) {
      p += pow(-1, i+j)*a[i][j]*det(minor(a[i][j]));
    }
    return p;
  }
}
