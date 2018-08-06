#include <stdio.h>

int succ(int x){
	return (++x);
}

int add(int a, int b){
}

int main(){
	int res =succ(3);
	printf("%d\n", res);
	return 0;
}
