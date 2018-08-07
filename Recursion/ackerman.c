#include <stdio.h>
#include <time.h>

int ackerman(int m, int n){
	if (m==0)
		return n+1;
	else if (m>0 && n==0)
		return ackerman(m-1, 1);
	else /*if (m>0 && n>0)*/
		return ackerman(m-1, ackerman(m, n-1));
}

int ackermanIter(int m, int n){
}

int main(){
	int ans = ackerman(3, 2);
	printf("%d\n", ans);
	return 0;
}