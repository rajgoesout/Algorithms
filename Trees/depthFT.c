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

void pretrav(NODEPTR tree){
	if (tree!=NULL){
		printf("%d\n", tree->info);//visit root
		pretrav(tree->left);//traverse left subtree
		pretrav(tree->right);//traverse right subtree
	}
}

void intrav(NODEPTR tree){
	if (tree!=NULL){
		intrav(tree->left);
		printf("%d\n", tree->info);
		intrav(tree->right);
	}
}

void posttrav(NODEPTR tree){
	if (tree!=NULL){
		posttrav(tree->left);
		posttrav(tree->right);
		printf("%d\n", tree->info);
	}
}

int main(){
	NODEPTR ptree, p, q;
	int number = 1;
	ptree = maketree(number);
	while (1) {
		p=q=ptree;
		number++;
		while (number != p->info && q != NULL) {
			p=q;
			if (number < p->info)
				q=p->left;
			else
				q=p->right;
		}
		if (number < p->info)
			setleft(p, number);
		else
			setright(p, number);
	}
}
