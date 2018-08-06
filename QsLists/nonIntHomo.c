#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char info[100];
	struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode(void);
void freenode(NODEPTR p);
void insertAfter(NODEPTR p, char x[]);
void deleteAfter(NODEPTR p, char *px);

int main(){
	NODEPTR myLinkedList = getnode();
	insertAfter(myLinkedList, "hello world!");//insert string info
	char *ptr;
	ptr = (char *) malloc(sizeof(myLinkedList));
	deleteAfter(myLinkedList, ptr);//store deleted node's info in ptr
	printf("%s\n", ptr);
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

void insertAfter(NODEPTR p, char x[]){
	NODEPTR q;
	if (p == NULL){
		printf("void insertion\n");
		exit(1);
	}
	q = getnode();
	strcpy(q->info, x);
	// q->info = x;
	q->next = p->next;
	p->next = q;
}

void deleteAfter(NODEPTR p, char *px){
	NODEPTR q;
	if ((p == NULL)||(p->next == NULL)){
		printf("void deletion\n");
		exit(1);
	}
	q = p->next;
	strcpy(px, q->info);
	// *px = q->info;
	p->next = q->next;
	freenode(q);
}
