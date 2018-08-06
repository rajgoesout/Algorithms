#include <stdio.h>
#include <stdlib.h>

#define MAXPQ 100

struct pqueue {
	int items[MAXPQ];
	int front; // position of the smallest element
	int rear; // 1 greater than position of the largest
};