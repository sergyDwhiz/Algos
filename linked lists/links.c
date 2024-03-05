#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head == NULL) {
       *head = new_node;
       return;
    }  
    struct Node* last = *head;  
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;    
}

// Function to delete a node with a given key
void deleteNode(struct Node **head, int key) {
    struct Node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next; 
        free(temp);               
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    printf("Created Linked list is: ");
    printList(head);
    deleteNode(&head, 3);
    printf("\nLinked List after Deletion of 3: ");
    printList(head);
    return 0;
}
