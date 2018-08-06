#include <stdio.h>

int product(int a[], int n){
	if (n == 1)
		return a[0];
	return a[n-1]*product(a, n-1);
}

int sum(int a[], int n){
	if (n == 1)
		return a[0];
	return a[n-1]+sum(a, n-1);
}

int average(int a[], int n){
	if (n == 1)
		return a[0];
	return (a[n-1]+sum(a, n-1))/n;
}

int max(int a[], int n){
	int m;
	if (n == 2)
		return (a[n-1]>a[n-2]) ? a[n-1] : a[n-2];
	return max(a, n-1);
}

int main(){
	int a[] = {1, -5, 17, 8, -17};
	int n = sizeof(a)/sizeof(a[0]);
	int ans = max(a, n);
	printf("%d\n", ans);
	return 0;
}