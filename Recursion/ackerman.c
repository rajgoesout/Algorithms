#include <stdio.h>

int ackerman(int m, int n){
	if (!m)
		return n+1;
	else if (!n)
		return ackerman(m-1, 1);
	else
		return ackerman(m-1, ackerman(m, n-1));
}

int ackermanIter(int m, int n){
	if (!m)
		return n+1;
	while (m){
		m--;
		if (!n){
			n++;
			return n+1;
		} else {
		}
	}
}

int main(){
	int ans = ackerman(2, 2);
	printf("%d\n", ans);
	return 0;
}