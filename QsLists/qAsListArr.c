#include <stdio.h>
#include <stdlib.h>
#define NUMNODES 500
#define TRUE 1
#define FALSE 0

struct nodetype
{
	int info, next;
};

struct nodetype node[NUMNODES];

struct queue
{
	int front, rear;
};

struct queue q;

int avail = 0;

int getnode(){
	int p;
	if (avail == -1){
		printf("overflow\n");
		exit(1);
	}
	p = avail;
	avail = node[avail].next;
	return p;
}

void freenode(int p){
	node[p].next = avail;
	avail = p;
	return;
}

int empty(struct queue *pq){
	return ((pq->front == -1)? TRUE: FALSE);
}

void insert(struct queue *pq, int x){
	int p;
	p = getnode();
	node[p].info = x;
	node[p].next = -1;
	if (pq->rear == -1)
		pq->front = p;
	else
		node[pq->rear].next = p;
	pq->rear = p;
}

int removeE(struct queue *pq){
	int p, x;
	if (empty(pq)){
		printf("queue underflow\n");
		exit(1);
	}
	p = pq->front;
	x = node[p].info;
	pq->front = node[p].next;
	if (pq->front == -1)
		pq->rear = -1;
	freenode(p);
	return x;
}

int main(){
	return 0;
}











