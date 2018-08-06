#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode(void);
void freenode(NODEPTR p);
void insertAfter(NODEPTR p, int x);
void deleteAfter(NODEPTR p, int *px);

int main(){
	NODEPTR myLinkedList = getnode();
	insertAfter(myLinkedList, 3);
	int *ptr;
	ptr = (int *) malloc(sizeof(int));
	deleteAfter(myLinkedList, ptr);
	// int val = (myLinkedList->next)->info;
	printf("%d\n", *ptr);
	freenode(myLinkedList);
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

void insertAfter(NODEPTR p, int x){
	NODEPTR q;
	if (p == NULL){
		printf("void insertion\n");
		exit(1);
	}
	q = getnode();
	q->info = x;
	q->next = p->next;
	p->next = q;
}

void deleteAfter(NODEPTR p, int *px){
	NODEPTR q;
	if ((p == NULL)||(p->next == NULL)){
		printf("void deletion\n");
		exit(1);
	}
	q = p->next;
	*px = q->info;
	p->next = q->next;
	freenode(q);
}
