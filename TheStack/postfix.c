#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <ctype.h>

// #define STACKSIZE 100
#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

struct stack
{
	int top;
	double items[MAXCOLS];
};

void push(struct stack *ps, double x);
int pop(struct stack *ps);
int empty(struct stack *ps);
int isDigit(char symb);
double oper(int symb, double op1, double op2);
double eval(char expr[]);

int main(){
	char expr[MAXCOLS];
	int position=0;
	while ((expr[position++]=getchar())!='\n')
		;
	expr[--position]='\0';
	printf("the original postfix expression is: %s\n", expr);
	printf("%f\n", eval(expr));
	return 0;
}

int isDigit(char symb){
	return (symb >= '0' && symb <= '9');
}

double oper(int symb, double op1, double op2){
	switch(symb){
		case '+' :	return (op1+op2);
		case '-' :	return (op1-op2);
		case '*' :	return (op1*op2);
		case '/' :	return (op1/op2);
		case '$' :	return (pow(op1, op2));
		default:
			printf("illegal operation\n");
			exit(1);
	}
}

int empty(struct stack *ps){
	return (ps->top == -1);
}

int pop(struct stack *ps){
	if (empty(ps)){
		printf("stack underflow\n");
		exit(1);
	}
	return (ps->items[ps->top--]);
}

void push(struct stack *ps, double x){
	if (ps->top == MAXCOLS - 1){
		printf("stack overflow\n");
		exit(1);
	}
	else
		ps->items[++(ps->top)] = x;
}

double eval(char expr[]){
	int c, position;
	double opnd1, opnd2, value;
	struct stack opndstk;

	opndstk.top = -1;
	for (position=0; (c=expr[position])!='\0'; position++)
		if (isDigit(c))
			push(&opndstk, (double) (c-'0'));//push the operand to stack
		else {
			opnd2 = pop(&opndstk);
			opnd1 = pop(&opndstk);//pop the previous 2 operands from the stack
			value = oper(c, opnd1, opnd2);//apply the operator to them
			push(&opndstk, value);//push the result
		}
	return pop(&opndstk);//pop final answer from stack
}








