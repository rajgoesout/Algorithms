#define MAXQUEUESIZE 100
#include <stdio.h>

struct Queue
{
	int maxQueueSize;
	void CreateQ(){
		struct element
		{
			int key;
		};
		element queue[MAXQUEUESIZE];
		int rear = -1;
		int front = -1;
	}

	int isFullQ(Queue queue){
		if (rear == MAXQUEUESIZE - 1)
			return 1;
		else
			return 0;
	}

	int isEmptyQ(Queue queue){
		if (front == rear)
			return 1;
		else
			return 0;
	}

	void addq(element item){
		if (rear == MAXQUEUESIZE-1)
			queueFull();
		else
			queue[++rear] = item;
	}

	element deleteq(){
		if (front == rear)
			queueEmpty();
		else
			return queue[++front];
	}

	void queueEmpty(){
		fprintf(stderr, "The queue is empty\n");
	}

	void queueFull(){
		fprintf(stderr, "The queue is full\n");
	}
};