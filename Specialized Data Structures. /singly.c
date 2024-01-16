// Complete code for a Single Linked List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Create a Node

struct slinklist{
    int data;
    struct slinklist* next;
};
typedef struct slinklist node;
node* start = NULL;
node* getnode()
{
    node* newnode = (node*) malloc(sizeof(node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->next= NULL;
    return newnode;
}
// Creating a singly with 'n' number of nodes
void createlist(int n){
    int i; 
    node* newnode;  // var for creating a new node
    node* temp;    // Temporal var for holding the first node
    for(i=0;i<n;i++)   
    {
        if(start==NULL){  // If list is empty
            start =  newnode;   // Make the new node the start node
        }
        else{
            temp = start;  // Make a temporary node to traverse the list
            while(temp-> next!=NULL) // Traverse the list until the last node
            temp =  temp -> next;  // Make the temporary node the last node
            temp -> next= newnode; // Add the new node to the end of the list
        }
    }
}
//Insert node at the beginning of the list
void inserbeg(int n){
    node* newnode;
    newnode = getnode();
    if(start == NULL){ // If list is empty
        start = newnode;  // Make the new node the start node
    }
    else{
        newnode->next = start; // Set the next pointer of newnode to the curent start node
        start = newnode; // Make the new node the first node
    }
    } 

    void inserbeg(int n){
        node* newnode;
        newnode = getnode();
        if(start == NULL){
            start = newnode;
        } else{
            newnode->next=start;
            start = newnode;
        }
    }