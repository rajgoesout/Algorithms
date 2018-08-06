#include <stdio.h>
#include <stdlib.h>

struct nodetype
{
	int info;
	struct nodetype *left;
	struct nodetype *right;
	// struct nodetype *father;
};

typedef struct nodetype *NODEPTR;

NODEPTR getnode(void){
	NODEPTR p;
	p = (NODEPTR) malloc(sizeof(struct nodetype));
	return p;
}

NODEPTR maketree(int x){
	NODEPTR p;
	p = getnode();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void setleft(NODEPTR p, int x){
	if (p==NULL)
		printf("void insertion\n");
	else if (p->left != NULL)
		printf("invalid insertion\n");
	else
		p->left = maketree(x);
}

void setright(NODEPTR p, int x){
	if (p==NULL)
		printf("void insertion\n");
	else if (p->right != NULL)
		printf("invalid insertion\n");
	else
		p->right = maketree(x);
}

int main(){
	NODEPTR ptree;
	NODEPTR p, q;
	int number;

	scanf("%d", &number);
	ptree = maketree(number);
	while (scanf("%d", &number) != EOF) {
		p=q=ptree;
		while (number != p->info && q != NULL) {
			p=q;
			if (number < p->info)
				q=p->left;
			else
				q=p->right;
		}
		if (number == p->info)
			printf("%d is a duplicate\n", number);
		else if (number < p->info)
			setleft(p, number);
		else
			setright(p, number);
	}
}
