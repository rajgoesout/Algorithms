#include <stdio.h>

int additions = 0;

unsigned int fibonacci(unsigned int n){
	if (n <= 1)
		return n;
	unsigned int lofib = 0, hifib = 1, i;
	for (i=2; i<=n; i++){
		unsigned int temp = lofib;
		lofib = hifib;
		hifib = temp + lofib;
		additions++;
	}
	return hifib;
}

unsigned int fibonacciRec(unsigned int n){
	if (n <= 1)
		return n;
	else
		additions++;
	return fibonacciRec(n-1) + fibonacciRec(n-2);
}

int gfib(int f0, int f1, int n){
	if (n == 0)
		return f0;
	else if (n == 1)
		return f1;
	return gfib(f0, f1, n-1) + gfib(f0, f1, n-2);
}

int main(){
	unsigned int f = fibonacci(10);
	printf("%u\n", f);
	printf("%d\n", additions);
	return 0;
}
