#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p, *q;
	p = (int *) malloc(sizeof(int));
	*p=5;
	q = (int *) malloc(sizeof(int));
	*q=8;
	free(p);
	p=q;
	q = (int *) malloc(sizeof(int));
	*q=6;
	printf("%d %d\n", *p, *q);
}