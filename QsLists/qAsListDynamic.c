#include <stdio.h>
#include <stdlib.h>
// #define NULL 0
#define TRUE 1
#define FALSE 0

struct node
{
	int info;
	struct node *next;
};

typedef struct node *NODEPTR;

struct queue
{
	NODEPTR front, rear;
};

struct queue q;

NODEPTR getnode(void){
	NODEPTR p;
	p = (NODEPTR) malloc(sizeof(struct node));
	return p;
}

void freenode(NODEPTR p){
	free(p);
}

int empty(struct queue *pq){
	return ((pq->front == NULL)? TRUE: FALSE);
}

void insert(struct queue *pq, int x){
	NODEPTR p;
	p = getnode();
	p->info = x;
	p->next = NULL;
	if (pq->rear == NULL)
		pq->front = p;
	else
		(pq->rear)->next = p;
	pq->rear = p;
}

int removeE(struct queue *pq){
	NODEPTR p;
	int x;
	if (empty(pq)){
		printf("queue underflow\n");
		exit(1);
	}
	p = pq->front;
	x = p->info;
	pq->front = p->next;
	if (pq->front == NULL)
		pq->rear = NULL;
	freenode(p);
	return x;
}

int main(){
	insert(&q, 5);
	int ans = empty(&q);
	printf("%d\n", ans);
	return 0;
}








