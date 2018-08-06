#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct rational
{
	int numerator;
	int denominator;
};

//reduce to lowest form (using Euclid's algorithm)
void reduce(struct rational *in, struct rational *out){
	int a, b, rem;

	if (in->numerator > in->denominator){
		a = in->numerator;
		b = in->denominator;
	} else {
		a = in->denominator;
		b = in->numerator;
	}
	while (b != 0){
		rem = a % b;
		a = b;
		b = rem;
	}

	out->numerator /= a;
	out->denominator /= a;
}

//input structs are passed as parameters
int equal(struct rational *rat1, struct rational *rat2){
	struct rational r1, r2;//output structs
	r1.numerator = rat1->numerator;
	r1.denominator = rat1->denominator;
	r2.numerator = rat2->numerator;
	r2.denominator = rat2->denominator;
	reduce(rat1, &r1);
	reduce(rat2, &r2);

	if (r1.numerator == r2.numerator && r1.denominator == r2.denominator)
		return TRUE;
	return FALSE;

	// reduce(rat1, rat1);
	// reduce(rat2, rat2);

	// if (rat1->numerator == rat2->numerator && rat1->denominator == rat2->denominator)
	// 	return TRUE;
	// return FALSE;
}

int equal2(struct rational *rat1, struct rational *rat2){
	if (rat1->numerator * rat2->denominator == rat2->numerator * rat1->denominator)
		return TRUE;
	return FALSE;
}

void multiply(struct rational *r1, struct rational *r2, struct rational *r3){
	// struct rational rat3;
	// rat3.numerator = r1->numerator * r2->numerator;
	// rat3.denominator = r1->denominator *r2->denominator;
	// r3->numerator = rat3.numerator;
	// r3->denominator = rat3.denominator;
	// reduce(&rat3, r3);
	r3->numerator = r1->numerator * r2->numerator;
	r3->denominator = r1->denominator *r2->denominator;
	reduce(r3, r3);
}

void add(struct rational *r1, struct rational *r2, struct rational *r3){
	r3->denominator = r1->denominator * r2->denominator;
	r3->numerator = (r1->numerator * r2->denominator) + (r2->numerator * r1->denominator);
	reduce(r3, r3);
}

void subtract(struct rational *r1, struct rational *r2, struct rational *r3){
	r3->denominator = r1->denominator * r2->denominator;
	r3->numerator = (r1->numerator * r2->denominator) - (r2->numerator * r1->denominator);
	reduce(r3, r3);
}

void divide(struct rational *r1, struct rational *r2, struct rational *r3){
	// struct rational rat3;
	// rat3.numerator = r1->numerator * r2->denominator;
	// rat3.denominator = r1->denominator *r2->numerator;
	// r3->numerator = rat3.numerator;
	// r3->denominator = rat3.denominator;
	// reduce(&rat3, r3);
	r3->numerator = r1->numerator * r2->denominator;
	r3->denominator = r1->denominator *r2->numerator;
	reduce(r3, r3);
}

int main(){
	struct rational one, two, three;
	one.numerator = 2;
	one.denominator = 3;
	two.numerator = 66;
	two.denominator = 99;

	if (equal2(&one, &two))
		printf("%d/%d and %d/%d are equal\n", one.numerator, one.denominator, two.numerator, two.denominator);
	else
		printf("%d/%d and %d/%d are not equal\n", one.numerator, one.denominator, two.numerator, two.denominator);

	multiply(&one, &two, &three);
	printf("%d/%d * %d/%d = %d/%d\n", one.numerator, one.denominator, two.numerator, two.denominator, three.numerator, three.denominator);

	add(&one, &two, &three);
	printf("%d/%d + %d/%d = %d/%d\n", one.numerator, one.denominator, two.numerator, two.denominator, three.numerator, three.denominator);

	subtract(&one, &two, &three);
	printf("%d/%d - %d/%d = %d/%d\n", one.numerator, one.denominator, two.numerator, two.denominator, three.numerator, three.denominator);

	divide(&one, &two, &three);
	printf("%d/%d / %d/%d = %d/%d\n", one.numerator, one.denominator, two.numerator, two.denominator, three.numerator, three.denominator);
	return 0;
}







