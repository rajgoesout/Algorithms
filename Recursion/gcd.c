#include <stdio.h>

int gcd(int x, int y){
  if (y <= x && x%y == 0)
    return y;
  else if (x < y)
    return gcd(y, x);
  else
    return gcd(y, x%y);
}

int gcdIter(int x, int y){
	int temp;
	if (x < y){
		temp = y;
		y = x;
		x = temp;
	}
	int t;
	while (x >= y){
		if (x%y == 0)
			return y;
		t = y;
		y = x%y;
		x = t;
	}
}

int main(){
  int ans = gcdIter(14, 11);
  printf("%d\n", ans);
  return 0;
}
