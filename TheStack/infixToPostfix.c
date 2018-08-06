#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0

struct stack
{
	int top;
	char items[MAXCOLS];
};

int empty(struct stack *ps);
void push(struct stack *ps, char x);
int pop(struct stack *ps);
void popandtest(struct stack *ps, char *px, int *pund);
int prcd(char a, char b);
void postfix(char infix[], char postr[]);

int main(){}

int empty(struct stack *ps){
	return (ps->top == 0);
}

int pop(struct stack *ps){
	if (empty(ps)){
		printf("stack underflow\n");
		exit(1);
	}
	return (ps->items[ps->top--]);
}

void push(struct stack *ps, char x){
	if (ps->top == MAXCOLS - 1){
		printf("stack overflow\n");
		exit(1);
	}
	else
		ps->items[++(ps->top)] = x;
}

void popandtest(struct stack *ps, char *px, int *pund){
	if (empty(ps)){
		*pund = 1;
		return;
	}
	*pund = 0;
	*px = ps->items[ps->top--];
	return;
}

int prcd(char a, char b){
	char op[] = {'+', '-', '*', '/', '^'};
	if (a=='(' && strchr(op, b))
		return FALSE;
	else if (b==')' && strchr(op, a))
		return FALSE;
	else if (a==')')
		exit(1);
	else if (a=='^')
		return TRUE;
	else if (a=='/')
		return TRUE;
	else if (a=='*')
		return TRUE;
	else if (a=='+')
		return TRUE;
	else if (a=='-')
		return TRUE;
}

void postfix(char infix[], char postr[]){
	int position, und;
	int outpos=0;
	char topsymb='+';
	char symb;
	struct stack opstk;
	opstk.top=-1;

	for (position=0; (symb=infix[position])!='\0'; position++)
		if (isOperand(symb))
			postr[outpos++]=symb;
		else{
			popandtest(&opstk, &topsymb, &und);
			while(!und && prcd(topsymb, symb)){
				postr[outpos++]=topsymb;
				popandtest(&opstk, &topsymb, &und);
			}
			if (!und)
				push(&opstk, topsymb);
			if (und || (symb != ')'))
				push(&opstk, symb);
			else
				topsymb=pop(&opstk);
		}
	while (!empty(&opstk))
		postr[outpos++]=pop(&opstk);
	postr[outpos]='\0';
	return;
}











