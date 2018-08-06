#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct realtype
{
	int left;
	int right;
};

void input(double n, struct realtype *c){
	c->left = (int)n;
	double decpart = n - (int)n;
}

double real(struct realtype *rt){
	double floating = (double)rt->right;
	int n, count = 0;
	n = rt->right;
	while (n != 0){
		n /= 10;
		count++;
	}
	int i=1;
	for(i=1; i<=count; i++) {
		floating/=10.0;
	}
	double no = (double)rt->left + floating;
	return no;
}

void add(struct realtype *r1, struct realtype *r2, struct realtype *r3){}

void subtract(struct realtype *r1, struct realtype *r2, struct realtype *r3){}

void multiply(struct realtype *r1, struct realtype *r2, struct realtype *r3){}

int main(){
	struct realtype no1, no2;
	no1.left = 57;
	no1.right = 986203;
	double rep = real(&no1);
	printf("%lf\n", rep);
	input(87.356, &no2);
	printf("%d %d\n", no2.left, no2.right);
	return 0;
}