// #include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
#define INT		1
#define FLOAT	2
#define STRING	3
#define TRUE	1
#define FALSE	0

struct stackelement {
	int etype = STRING;

	union {
		int ival;
		float fval;
		char *pval;
	} element;
};

struct stack {
	int top;
	struct stackelement items[STACKSIZE];
	// int items[STACKSIZE];
};

int empty(struct stack *ps);
char pop(struct stack *ps);
void push(struct stack *ps, char x);
char stacktop(struct stack *ps);

int pattern();

int main(){
	/*struct stack x, s, y;
	int l = 0, i;
	char c;
	while ((c = getchar()) != 'C')
		push(&x, c);
	pop(&x);
	while (!empty(&x)){
		push(&s, pop(&x));
		l++;
	}
	while ((c = getchar()) != '\n')
		push(&y, c);
	pop(&y);
	for (i=1; i<=l; i++)
		if (!pop(&s) == pop(&y))
			return 0;
	return 1;*/
	printf("%d\n", pattern());
	return 0;
}

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

void popandtest(struct stack *ps, int *px, int *pund){
	if (empty(ps)){
		*pund = 1;
		return;
	}
	*pund = 0;
	*px = ps->items[ps->top--];
	return;
}

void push(struct stack *ps, int x){
	if (ps->top == STACKSIZE - 1){
		printf("stack overflow\n");
		exit(1);
	}
	else
		ps->items[++(ps->top)] = x;
}

void pushandtest(struct stack *ps, int x, int *pund){
	if (ps->top == STACKSIZE - 1){
		*pund = 1;
		return;
	}
	*pund = 0;
	ps->items[++(ps->top)] = x;
	return;
}

int stacktop(struct stack *ps){
	if (empty(ps)){
		printf("stack underflow\n");
		exit(1);
	}
	else
		return (ps->items[ps->top]);
}

int pattern(){
	struct stack x, s, y;
	int l = 0, i;
	char c;
	while ((c = getchar()) != 'C')
		push(&x, c);
	pop(&x);
	while (!empty(&x)){
		push(&s, pop(&x));
		l++;
	}
	while ((c = getchar()) != '\n')
		push(&y, c);
	pop(&y);
	for (i=1; i<=l; i++)
		if (!(pop(&s) == pop(&y)))
			return 0;
	return 1;
}




