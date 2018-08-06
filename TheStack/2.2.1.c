#include "stack.h"

int main(){
	int element;
	// initialize stack
	for (element = 1; element <= 6; element++)
		push(&s, element);

	// (a)
	/*pop(&s);
	int i = pop(&s);
	printf("%d\n", i);
	printf("%d\n", stacktop(&s));*/

	// (b)
	/*int x = pop(&s);
	int i = pop(&s);
	push(&s, i);
	push(&s, x);
	printf("%d\n", i);
	printf("%d\n", stacktop(&s));*/

	// (c)
	/*int n = 5, i;
	while (n--)
		i = pop(&s);
	printf("%d\n", i);
	printf("%d\n", stacktop(&s));*/

	// (d)
	/*int j = 0, a[STACKSIZE], n = 5, i;
	while (n--){
		a[j] = pop(&s);
		j++;
	}
	j--;
	i = a[j];
	while (j >= 0){
		push(&s, a[j]);
		j--;
	}
	printf("%d\n", i);
	printf("%d\n", stacktop(&s));*/

	// (e)
	/*int i;
	while (!empty(&s))
		i = pop(&s);
	printf("%d\n", i);
	printf("%d\n", stacktop(&s));*/

	// (f)
	/*int i;
	struct stack s2;
	while (!empty(&s)){
		i = pop(&s);
		push(&s2, i);
	}
	while (!empty(&s2))
		push(&s, pop(&s2));
	printf("%d\n", i);
	printf("%d\n", stacktop(&s));*/

	// (g)
	/*int j, n = 0, i;
	struct stack s2;
	while (!empty(&s)){
		push(&s2, pop(&s));
		n++;
	}
	for (j=1; j<=n; j++)
		if (j == 3){
			i = pop(&s2);
			push(&s, i);
		} else {
			push(&s, pop(&s2));
		}
	printf("%d\n", i);
	printf("%d\n", stacktop(&s));*/


	/*printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));*/
	return 0;
}







