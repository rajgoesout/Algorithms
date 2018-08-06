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
int empty(NODEPTR *pq);
void push(NODEPTR *pq, int x);
void insert(NODEPTR *pq, int x);
int delete(NODEPTR *pq);

int main(){
	printf("hello, world!\n");
	NODEPTR queueNode = getnode();
	int ans = empty(&queueNode);
	printf("%d\n", ans);
	push(&queueNode, 5);
	int value = delete(&queueNode);
	printf("%d\n", value);
	freenode(queueNode);
	// pop(&queueNode);
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

int empty(NODEPTR *pq){
    return ((*pq==NULL)? TRUE: FALSE);
}

int delete(NODEPTR *pq){
	int x;
	NODEPTR p;
	if (empty(pq)){
		printf("stack underflow\n");
		exit(1);
	}
	p = (*pq)->next;
	x = p->info;
	if (p == *pq)
		pq = NULL;
	else
		(*pq)->next = p->next;
	freenode(p);
	return x;
}

void push(NODEPTR *pq, int x){
    NODEPTR p;
    p = getnode();//get a node from the available nodes in memory
    p->info = x;//set the info field equal to x
    // insert node p after node pstack
    if (empty(pq))
        *pq = p;
    else
        p->next = (*pq)->next;
    (*pq)->next = p;
}
/*
	insert(&q, x); same as:
	push(&q, x);
	q = q->next;
*/
void insert(NODEPTR *pq, int x){
	NODEPTR p;
	p = getnode();
	p->info = x;
	if (empty(pq))
		*pq = p;
	else
		p->next = (*pq)->next;
	(*pq)->next = p;
	*pq = p;
	return;
}
