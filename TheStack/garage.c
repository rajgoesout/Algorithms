#include <stdio.h>
#include <stdlib.h>

struct garage
{
	int top;
	char x[10];//'A' or 'D'
	int n[10];//licence plate no.
	int count = 0;//no. of times car was moved out
	struct car
	{
		int n;
		int count = 0;
	};
};

int empty(struct garage *pg);
int pop(struct garage *pg, int n);
void push(struct garage *pg, int n);

struct garage g;

int main(){
	char c;
	int no;

	g.top = -1;//empty garage

	while ((c = getchar())!=EOF){
		scanf("%d", &no);
		if (c == 'A')
			push();
		else if (c == 'D')
			pop();
	}
}

int empty(struct garage *pg){
	return (pg->top == -1);
}

int pop(struct garage *pg, int n){
	if (empty(pg))
		printf("garage is empty\n");
	else{
		while (n != num){
			int num = pg->n[pg->top--];
			pg->n[]
		}
	}
}

void push(struct garage *pg, int n){}






