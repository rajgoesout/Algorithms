#include <stdio.h>
#include <stdlib.h>
#define NUMNODES 500

struct nodetype
{
	int info, next;
};

struct nodetype node[NUMNODES];

int avail = 0;

void deleteAfter(int p, int *px);
void insertAfter(int p, int x);
void freenode(int p);
int getnode();

int main(){
	int i;
	for (i = 0; i < NUMNODES-1; i++)
		node[i].next = i+1;
	node[NUMNODES-1].next = -1;
	int x;
	for(i=0;i<10;i++)
		x = getnode();
	int *ptr;
	int no=17;
	ptr=&no;
	// deleteAfter(7, ptr);
	insertAfter(7, 17);
	freenode(7);
	printf("%d\n", node[7].info);
	return 0;
}

// removes a node from the available list & returns a ptr to it
int getnode(){
	int p;
	if(avail==-1){ // if no nodes are available
		printf("overflow\n");
		exit(1);
	}
	p=avail;
	avail = node[avail].next;
	return p;
}

// accepts a ptr to a node & returns that node to the available list
void freenode(int p){
	node[p].next = avail;
	avail=p;
	return;
}

//insert x into a node following the node pointed to by p
void insertAfter(int p, int x){
	if(p==-1){ // check if p is null
		printf("void insertion\n");
		exit(1);
	}
	int q = getnode();
	node[q].info = x;
	node[q].next = node[p].next;
	node[p].next = q;
	return;
}

//deletes the node following node(p) and stores its contents in px
void deleteAfter(int p, int *px){
	int q;
	if((p==-1)||(node[p].next == -1)){
		printf("void deletion\n");
		return;
	}
	q=node[p].next;//node next to p
	*px = node[q].info;//info of node next to p
	node[p].next=node[q].next;//make p point to the node next to q
	freenode(q);
	return;
}


