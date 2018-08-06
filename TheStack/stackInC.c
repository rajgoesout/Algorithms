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

int main(){
	// se = s.items[s.top];
	// switch (se.etype){
	// 	case INT  	: printf("% d\n", se.ival);
	// 	case FLOAT 	: printf("% f\n", se.fval);
	// 	case STRING	: printf("% s\n", se.pval);
	// }

	s.top = -1; // empty stack
	
	printf("%d\n", empty(&s));

	push(&s, 5);

	printf("%d\n", empty(&s));

	printf("%d\n", stacktop(&s));

	push(&s, 17);
	push(&s, -3);
	push(&s, 12);

	printf("%d\n", stacktop(&s));

	// pop(&s);
	// pop(&s);
	// int i = stacktop(&s);

	int i = (s->(top-2));

	printf("%d\n", i);
}

int empty(struct stack *ps){
	// if (ps->top == -1)
	// 	return TRUE;
	// else
	// 	return FALSE;
	return (ps->top == -1); // same as above if-else block
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



