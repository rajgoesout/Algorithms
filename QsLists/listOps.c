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
void push(NODEPTR *pl, int x);
void place(NODEPTR *plist, int x);
void insertEnd(NODEPTR *plist, int x);
void removex(NODEPTR *plist, int x);

int *y;

int main(){
	// y = (int *) malloc(sizeof(int));
	NODEPTR myLinkedList = getnode();
	freenode(myLinkedList);
	removex(&myLinkedList, 2);
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

void push(NODEPTR *pl, int x){
	NODEPTR p;
	p = getnode();
	p->info = pl;
	pl = p;
}

// insert x at its proper position in a sorted linear list
void place(NODEPTR *plist, int x){
	NODEPTR p, q;
	q = NULL;
	for (p = *plist; p != NULL && x > p->info; p = p->next)
		q = p;
	if (q == NULL)
		push(plist, x);
	else
		insertAfter(q, x);
}

// insert x at the end of a list
void insertEnd(NODEPTR *plist, int x){
	NODEPTR p, q;
	p = getnode();
	p->info = x;
	p->next = NULL;
	if (*plist == NULL)
		*plist = p;
	else {
		for (q = *plist; q->next != NULL; q = q->next)
			;
		q->next = p;
	}
}

// returns a pointer to the first occurence of x
NODEPTR search(NODEPTR list, int x){
	NODEPTR p;
	for (p = list; p != NULL; p = p->next)
		if (p->info == x)
			return p;
	return NULL;
}

// delete all nodes whose info field contains x
void removex(NODEPTR *plist, int x){
	NODEPTR p, q;
	int y;
	q = NULL;
	p = *plist;
	while (p)
		if (p->info == x){
			p = p->next;
			if (q == NULL){
				freenode(*plist);
				*plist = p;
			} else
				deleteAfter(q, &y);
		} else {
			q = p;
			p = p->next;
		}
}
