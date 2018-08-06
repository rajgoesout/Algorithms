#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data){
    if (prev_node == NULL){
        printf("The given previous node cannot be null\n");
        return;
    }
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL; // this new node is going to be the last node

    if (*head_ref == NULL){
        *head_ref = new_node; // if linked lust is empty, make this new node as head
        return;
    }
    
    while (last->next != NULL) // else traverse till the last node
        last = last->next;
    
    last->next = new_node; // change the next of the last node
    return;
}

void printList(struct Node *n){
    while(n != NULL){
        printf("%d\t", n->data);
        n = n->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);

    push(&head, 10);

    printList(head);

    insertAfter(head, 13);

    printList(head);

    append(&head, 0);

    printList(head);

    return 0;
}