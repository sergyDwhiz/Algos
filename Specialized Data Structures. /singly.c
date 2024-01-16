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
node* getnode()
{
    node* newnode = (node*) malloc(sizeof(node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->next= NULL;
    return newnode;
}
