#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct listNode *listPointer;
struct listNode
{
    int data;
    listPointer link;
};


void push(struct Node** head_ref, int new_data){ // reference (pointer to pointer) to head of a list and an int (data) are passed
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref, int key){ // reference (pointer to pointer) to head of a list and key (to be deleted) are passed
    // Store head node
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

void delete(listPointer *first, listPointer trail, listPointer x){ // delete x from the list, trail is preceding node, *first is front of the list
    if (trail) // if trail != 0 (if we are not deleting the first node)
        trail->link = x->link;
    else // we r deleting the first node
        *first = (*first->link);
    free(x);
}

void delete2(listPointer *first, listPointer *trail){
    if (*trail)
        (*trail)->link = ((*trail)+1)->link;
    else
        *first = (*first->link);
    free((*trail)+1);
}
