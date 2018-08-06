#include <iostream>
using namespace std;

int top;

void check(char str[], int n, char stack[]){
	for (int i=0; i<n; i++){
		if (str[i] == '('){
			top = top + 1;
			stack[top] = '(';	// push
		}
		if (str[i] == ')'){
			if (top == -1){		// stack is empty
				top = top - 1;	// pop
				break;			// come out of loop
			} else {			// stack is not empty
				top = top - 1;	// pop
			}
		}
	}
	if (top == -1)	// no. of '(' == no. of ')'
		cout << "String is balanced\n";
	else			// no. of '(' != no. of ')'
		cout << "String is unbalanced\n";
}

int main(){
	char str1[] = {'(', 'a', '+', '(', 'b', '-', 'c', ')', ')'};
	char str2[] = {'(', '(', 'a', '+', 'b', ')'};

	char myStack[15];
	top = -1;
	check(str1, 9, myStack);
	top = -1;
	check(str2, 6, myStack);

	return 0;
}