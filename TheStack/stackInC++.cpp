#include <iostream>
#include <cstdlib>
using namespace std;

const int stackSize = 100;

class Stack{
	int top;
	int items[stackSize];
public:
	Stack(){
		top = -1;
	}

	bool isEmpty(Stack *ps){
		return (ps->top == -1);
	}

	int pop(Stack *ps){
		if (isEmpty(ps)){
			cout << "Stack Underflow" << endl;
			exit(1);
		}
		return (ps->items[ps->top--]);
	}

	void push(Stack *ps, int x){
		if (ps->top == stackSize - 1){
			cout << "Stack overflow" << endl;
			exit(1);
		}
		ps->items[++(ps->top)] = x;
	}

	int stackTop(Stack *ps){
		if (isEmpty(ps)){
			cout << "Stack Underflow" << endl;
			exit(1);
		}
		return (ps->items[ps->top]);
	}

	int size(Stack *ps){
		return top+1;
	}
};

int main(){
	Stack stackObj;
	Stack *stackPtr;
	stackPtr = &stackObj;
	// stackObj.top = -1;
	// cout << stackObj.stackTop(stackPtr) << endl;
	cout << stackObj.isEmpty(stackPtr) << endl;
	// stackObj.pop(stackPtr);
	stackObj.push(stackPtr, 3);
	stackObj.push(stackPtr, -8);
	cout << stackObj.isEmpty(stackPtr) << endl;
	cout << stackObj.stackTop(stackPtr) << endl;
	stackObj.push(stackPtr, 3);
	cout << stackObj.pop(stackPtr) << endl;
	stackObj.push(stackPtr, 5);
	stackObj.push(stackPtr, 0);
	stackObj.push(stackPtr, 11);
	cout << stackObj.stackTop(stackPtr) << endl;
	cout << stackObj.size(stackPtr) << endl;
}
