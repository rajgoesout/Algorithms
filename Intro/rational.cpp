#include <iostream>
#include <cstdlib>
using namespace std;

class Rational
{
	long numerator;
	long denominator;
	void reduce();
public:
	Rational add(Rational);
	Rational mult(Rational);
	Rational divide(Rational);
	int equal(Rational);
	void print();
	void setrational(long n, long d){
		if (d == 0)
			error()
	}
};