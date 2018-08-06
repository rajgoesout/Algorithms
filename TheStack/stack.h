#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
#define INT		1
#define FLOAT	2
#define STRING	3
#define TRUE	1
#define FALSE	0

// struct stackelement {
// 	int etype = INT;

// 	union {
// 		int ival;
// 		float fval;
// 		char *pval;
// 	} element;
// };

struct stack {
	int top;
	// struct stackelement items[STACKSIZE];
	int items[STACKSIZE];
};

int empty(struct stack *ps);
int pop(struct stack *ps);
void push(struct stack *ps, int x);
int stacktop(struct stack *ps);

struct stack s;
// struct stackelement se;

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



