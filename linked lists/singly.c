// Complete code for a Single Linked List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Create a Node struct

struct slinklist{
    int data;
    struct slinklist* next;
};
typedef struct slinklist node;
node *start = NULL;
// Create a Node
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
    void inserend(int n){
        node* newnode;
        node* temp;
        newnode = getnode();
        if(start == NULL){
            start = newnode;
        }
        else{
            temp = start;
            while(temp->next!=NULL){
                temp = temp->next;
                temp-> next = newnode;
            }
        }
    }
 // Insert an element at an arbitary position
    void insert_at_mid(){
        node *prev, *newnode, *temp;
        int pos, nodectr, ctr=1;
        newnode = getnode();
        printf("Enter the position:\n");
        scanf("%d", &pos);
        nodectr = startnode(start);
        if(pos>1 && pos<nodectr){
            temp = prev = start;
            while (ctr<pos)
            {
                prev = temp;
                temp = temp -> next;
                ctr++;
            }
            prev-> next = newnode;
            newnode -> next = temp;
        }
        else{
            printf("Position %d is not at middle position\n", pos);
        }

    }
    // Delete an Element at the begining of Node. (Also called First or Head Node.)
    void delbeg(){
        node* temp;
        if(start == NULL){
            printf("\n No nodes exist\n");
            return;
        }
        else{
            temp = start; 
            start = temp-> next;
            free(temp);
            printf("\n Node deleted");
        }
    }
    // Delete Elt at End (Tail Node.)
    void del_last(){
        node* temp, *prev;
        if(start == NULL){
            printf("List is empty\n");
            return;
        }
        else{
            temp = start;
            prev = start; 
            while(temp->next!=NULL)
            {
                prev = temp;
                temp = temp -> next;
            }
            prev-> next = NULL;
            free(temp);
            printf("Node deleted\n");
        }
    }
    //Delete an arbitary Node. 
    void del_at_mid(){
        int ctr =1, pos, nodectr;
        node *temp, *prev;
        if(start == NULL)
        {
            printf("Empty List\n");
            return;
        }
        else{
            printf("Enter pos of node to delete\n");
            scanf("%d", &pos);
            nodectr = countnode(start);
            if(pos>nodectr){
                printf("Position doesn't exist\n");
            } if(pos >1 && pos <nodectr){
                temp = prev = start;
                while (ctr<pos){
                    prev= temp;
                    temp = temp -> next; 
                    ctr++;
                }    
                prev-> next = temp-> next;
                free(temp);
                printf("Node Deleted\n");
            }
            else{
                printf("\n Invalid Option\n");
                getch();
            }
        }
    }
    // Traverse the List from L -> R
    void traverse()
    {
        node *temp;
        temp = start;
        printf("\n The contents of List (Left to Right):\n"); 
        if(start == NULL )
        printf("\n Empty List");
        else{
        while (temp != NULL)
            {
            printf("%d ->", temp -> data);
            temp=temp-> data;
            }
            }
            printf("X");
            // Count number of Nodes: 
            void countnodes(node* st){
                if(st == NULL){
                    return 0;
                }else{
                    return (1+countnodes(st-> next));
                }
            }