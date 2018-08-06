#include <stdio.h>

#define NUMNODES 500

struct nodetype
{
	int info, left, right, father;
};

struct nodetype node[NUMNODES]; //array of nodes

int main(){
	int avail, i;
	avail=1;
	for (i=0; i<NUMNODES; i++)
		node[i].left = i+1;
	node[NUMNODES-1].left = 0;
}
