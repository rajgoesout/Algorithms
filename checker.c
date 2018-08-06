#include <stdio.h>

int n = -1;

void push(int s[], int a){
	s[n] = a;
	n++;
}

int isEmpty(int s[]){
	if (n == 0)
		return 1;
	else
		return 0;
}

int pop(int s[]){
	return s[n--];
}

int main(){
	int valid = 1, c, i;
	int stack[100];
	while ((c = getchar()) != '\n'){
		if (c == '(' || c == '[' || c == '{')
			push(stack, c);
		if (c == ')' || c == ']' || c == '}'){
			if (isEmpty(stack))
				valid = 0;
			else {
				i = pop(stack);
				if ((c == ')' && i != '(')||(c == ']' && i != '[')||(c == '}' && i != '{'))
					valid = 0;
				// switch (c){
				// 	case ')':
				// 		if (i != '(')
				// 			valid = 0;
				// 		break;
				// 	case ']':
				// 		if (i != '[')
				// 			valid = 0;
				// 		break;
				// 	case '}':
				// 		if (i != '{')
				// 			valid = 0;
				// 		break;
				// }
			}
		}
	}
	if (!isEmpty(stack))
		valid = 0;
	if (valid)
		printf("The string is valid\n");
	else
		printf("The string is invalid\n");
	return 0;
}