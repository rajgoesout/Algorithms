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

	while (x >= y){
		if (x%y == 0)
			return y;
		int t = y;
		y = x%y;
		x = y;
	}
}

int main(){
  int ans = gcdIter(4, 10);
  printf("%d\n", ans);
  return 0;
}
