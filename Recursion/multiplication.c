#include <stdio.h>

int multiplication(int a, int b){
	if (b == 1)
		return a;
	return multiplication(a, b-1) + a;
}

int main(){
	int ans = multiplication(6, 1004);
	printf("%d\n", ans);
	return 0;
}