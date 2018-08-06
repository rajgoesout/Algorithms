#include <iostream>
using namespace std;

int top = -1;

bool isEmpty(){
	if (top == -1)
		return true;
	else
		return false;
}

int topElement(int stack[]){
	return stack[top];
}

int size(){
	return top + 1;
}

void push(int stack[], int x, int n){
	if (top == n-1){	// if top position is the last position of stack
		cout << "Stack is full...Overflow\n";
	} else {
		top = top + 1;
		stack[top] = x;
	}
}

void pop(){
	if (isEmpty()){
		cout << "Stack is empty...Underflow\n";
	} else {
		top = top - 1;
	}
}

int main(){
	int myStack[3];

	push(myStack, 5, 3);

	cout << "Current size of the stack is: " << size() << endl;

	push(myStack, 10, 3);
	push(myStack, 24, 3);

	cout << "Current size of the stack is: " << size() << endl;

	push(myStack, 12, 3);	// Overflow condition

	cout << "The current top element in the stack is: " << topElement(myStack) << endl;

	for (int i=0; i<3; i++)
		pop();

	cout << "Current size of the stack is: " << size() << endl;

	pop();	// Underflow condition
}