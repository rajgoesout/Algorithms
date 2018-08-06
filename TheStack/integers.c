#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
#define INT		1
#define FLOAT	2
#define STRING	3
#define TRUE	1
#define FALSE	0

struct stack {
	int top;
	int item[STACKSIZE];
};