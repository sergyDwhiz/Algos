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
    node* newnode;
    node* temp;
    for(i=0;i<n;i++)
    {
        if(start==NULL){
            start =  newnode;
        }
        else{
            temp = start;
            while(temp-> next!=NULL)
            temp =  temp -> next;
            temp -> next= newnode;
        }
    }
}
//Insert node at the beginning of the list
void inserbeg(int n){
    node* newnode;
    newnode = getnode();
    if(start == NULL){
        start = newnode;
    }
    else{
        newnode->next = start;
        start = newnode;
    }
    } 