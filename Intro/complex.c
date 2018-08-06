#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complex
{
	int real;
	int imag;
};

void display(struct complex *c){
	char op;
	if (c->imag > 0)
		printf("%d + i%d\n", c->real, c->imag);
	else if (c->imag < 0)
		printf("%d - i%d\n", c->real, -c->imag);
	else
		printf("%d\n", c->real);
}

void add(struct complex *c1, struct complex *c2, struct complex *c3){
	c3->real = c1->real + c2->real;
	c3->imag = c1->imag + c2->imag;
}

double mod(struct complex *c){
	double absolute = sqrt(pow(c->real, 2)+pow(c->imag, 2));
	return absolute;
}

void multiply(struct complex *c1, struct complex *c2, struct complex *c3){
	c3->real = (c1->real * c2->real - c1->imag * c2->imag);
	c3->imag = (c1->imag * c2->real + c1->real * c2->imag);
}

void negate(struct complex *c){
	c->real *= -1;
	c->imag *= -1;
}

int main(){
	struct complex cno, cno2, cno3, cno4;
	cno.real = 4;
	cno.imag = -3;
	cno2.real = 11;
	cno2.imag = 8;
	display(&cno);
	display(&cno2);
	// double abso = mod(&cno);
	// printf("%lf\n", abso);
	// negate(&cno);
	// display(&cno);
	add(&cno, &cno2, &cno3);
	display(&cno3);
	multiply(&cno, &cno2, &cno4);
	display(&cno4);
	return 0;
}



