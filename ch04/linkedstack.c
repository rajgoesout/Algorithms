#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \    
    if (!((p) = malloc(s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

#define MAX_STACKS 10

void stackEmpty(){
    fprintf(stderr, "Stack is empty\n");
    exit(EXIT_FAILURE);
}

struct element
{
    int key;
};

typedef struct stack *stackPointer;
struct stack
{
    element data;
    stackPointer link;
};

stackPointer top[MAX_STACKS]

// add item to ith stack
void push(int i, element item){
    stackPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = item;
    temp->link = top[i];
}

// remove top element from ith stack
element pop(int i){
    stackPointer temp = top[i];
    element item;
    if (!temp)
        return stackEmpty();
    item = temp->data;
    top[i] = temp->link;
    free(temp);
    return item;
}

int main(){
    
}