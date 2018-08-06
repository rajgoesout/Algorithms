#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node
{
	int info;
	struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode(void);
void freenode(NODEPTR p);
int empty(NODEPTR *pstack);
void push(NODEPTR *pstack, int x);
int pop(NODEPTR *pstack);

int main(){
	printf("hello, world!\n");
	NODEPTR stackNode = getnode();
	int ans = empty(&stackNode);
	printf("%d\n", ans);
	push(&stackNode, 5);
	int value = pop(&stackNode);
	printf("%d\n", value);
	// freenode(stackNode);
	// pop(&stackNode);
	return 0;
}

NODEPTR getnode(void){
	NODEPTR p;
	p = (NODEPTR) malloc(sizeof(struct node));
	return p;
}

void freenode(NODEPTR p){
	free(p);
}

int empty(NODEPTR *pstack){
    return ((*pstack==NULL)? TRUE: FALSE);
}

void push(NODEPTR *pstack, int x){
    NODEPTR p;
    p = getnode();//get a node from the available nodes in memory
    p->info = x;//set the info field equal to x
    // insert node p after node pstack
    if (empty(pstack))
        *pstack = p;
    else
        p->next = (*pstack)->next;
    (*pstack)->next = p;
}

int pop(NODEPTR *pstack){
	int x;
	NODEPTR p;
	if (empty(pstack)){
		printf("stack underflow\n");
		exit(1);
	}
	p = (*pstack)->next;
	x = p->info;
	if (p == *pstack)
		pstack = NULL;
	else
		(*pstack)->next = p->next;
	freenode(p);
	return x;
}
