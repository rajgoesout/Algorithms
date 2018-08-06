#include <stdio.h>

int fibon(int n);

int main(){
	int ans = fibon(5);
	printf("%d\n", ans);
}

int fibon(int n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (fibon(n-1)+fibon(n-2));
}