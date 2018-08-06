#define MAXQUEUESIZE 100
#include <stdio.h>

struct CircularQueue
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

	void queueEmpty(){
		fprintf(stderr, "The queue is empty\n");
	}

	void queueFull(){
		fprintf(stderr, "The queue is full\n");
	}

	void addq(element item){
		if ((rear+1 == front)||(rear == MAXQUEUESIZE-1)||!front)
			queueFull();
		else {
			queue[rear] = item;
			rear = (rear+1) % MAXQUEUESIZE;
		}
	}

	void deleteq(){
		int i;
		element temp;
		if (front == rear)
			queueEmpty();
		else {
			temp = queue[front];
			front = (front+1) % MAXQUEUESIZE;
			return temp;
		}
	}
};