#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 100

struct queue {
	int items[MAXQUEUE];
	int front; // index immediately preceding first element
	int rear;
} q;

int empty(struct queue *pq);
int removeE(struct queue *pq);
void insert(struct queue *pq, int x);

int main(){
	q.front = q.rear = MAXQUEUE-1; // array is initially empty
	printf("%d\n", empty(&q));
	insert(&q, 5);
	printf("%d\n", empty(&q));
	insert(&q, 11);
	insert(&q, -3);
	insert(&q, 0);
	insert(&q, -5);
	printf("%d\n", removeE(&q));
}

int empty(struct queue *pq){
	return (pq->front == pq->rear);
}

int removeE(struct queue *pq){
	if (empty(pq)){
		printf("Queue underflow\n");
		exit(1);
	}
	if (pq->front == MAXQUEUE-1)
		pq->front = 0;
	else
		(pq->front)++;
	return pq->items[pq->front];
}

void insert(struct queue *pq, int x){
	if (pq->rear == MAXQUEUE-1)
		pq->rear = 0;
	else
		(pq->rear)++;
	if (pq->rear == pq->front){
		printf("Queue overflow\n");
		exit(1);
	}
	pq->items[pq->rear] = x;
}
