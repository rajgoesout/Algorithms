

public class stackInJava {

	// int stackSize = 100;

	public static void main(String[] args) {
		Stack myStk = new Stack();
		boolean val = myStk.isEmpty();
		System.out.println(val);
	}
}

// public class Stack {
	
// 	private int top;
// 	private int items[] = new int [stackSize];

// 	public Stack(){
// 		top = -1;
// 	}

// 	public boolean isEmpty(){
// 		return top == -1;
// 	}

// 	public int pop(){
// 		if (isEmpty()){
// 			System.out.println("Stack underflow");
// 			// throw NegativeArraySizeException;
// 			return -1;
// 		}
// 		return items[top--];
// 	}

// 	public void push(int x){
// 		if (top == stackSize - 1){
// 			System.out.println("Stack overflow");
// 			// throw IndexOutOfBoundsException;
// 			return;
// 		}
// 		items[top++] = x;
// 	}

// 	public int stackTop(){
// 		if (isEmpty()){
// 			System.out.println("Stack underflow");
// 			// throw NegativeArraySizeException;
// 			return -1;
// 		}
// 		return items[top];
// 	}

// 	public int size(){
// 		return top+1;
// 	}
// }