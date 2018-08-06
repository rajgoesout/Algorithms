#include <stdio.h>

int multiplyIter(int a, int b){
	int i, ans = 0;
	for (i=1; i<=b; i++)
		ans += a;
	return ans;
}

int main(){
	int prod = multiplyIter(3, 1);
	printf("%d\n", prod);
	return 0;
}