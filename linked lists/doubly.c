// Complete source code for a Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Create a Node 
struct dslinklist{
    struct dslinklist* left;
    int data;
    struct slinklist* right;
};
typedef struct dslinklist node;
node* start = NULL;
node* getnode()
{
    node* newnode; 
    newnode = (node*) malloc(sizeof(node));
    printf("Enter data: \n");
    scanf("%d", &newnode -> data);
    newnode->left = NULL;
    newnode -> right = NULL;
    return newnode;
};

// Creat a double list with 'n' Nodes
void createlist(int n)
{   
    int i; 
    node* newnode;
    node* temp;
    for(i=0;i<n;i++){
        newnode = getnode(); // Create a new node
        if(start==NULL){  // If list is empty
            start = newnode;  // Make the new node the start node
        }
        else{  // If it's not empty, add the new node to the end of the list
            temp = start;  // Make a temporary node to traverse the list    
            while(temp -> right) // Traverse the list until the last node
            temp = temp -> right; // Make the temporary node the last node
            temp-> right = newnode;  // Add the new node to the end of the list
            newnode->left = temp; // Make the new node point to the previous node
        }
    }
}
void inserbeg(int n){
    node* newnode;
    newnode = getnode();
    if(start == NULL){
        start = newnode;
    }
    else{
        newnode->right = start;
        start->left = newnode;
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
            temp= start;
            while(temp->right!=NULL){
                temp = temp->right;
                temp-> right = newnode;
                newnode->left = temp;
            }
        }
    }
    void insertpos(int n){
        node* newnode;
        node* temp;
        int pos, i;
        printf("Enter the position: \n");
        scanf("%d", &pos);
        if(pos==1){
            inserbeg(n);
        }
        else{
            newnode = getnode();
            temp = start;
            for(i=1;i<pos-1;i++){
                temp = temp->right;
                if(temp==NULL){
                    printf("There are less than %d elements in the list\n", pos);
                    return;
                }
            }
            newnode->right = temp->right;
            newnode->left = temp;
            if(temp->right!=NULL){
                temp->right->left = newnode;
            }
            temp->right = newnode;
        }
    }
    void deletebeg(){
        node* temp;
        if(start==NULL){
            printf("List is empty\n");
        }
        else{
            temp = start;
            start = start->right;
            start->left = NULL;
            free(temp);
        }
    }
    void deleteend(){
        node* temp;
        if(start==NULL){
            printf("List is empty\n");
        }
        else{
            temp = start;
            while(temp->right!=NULL){
                temp = temp->right;
            }
            temp->left->right = NULL;
            free(temp);
        }
    }
    void deletepos(){
        node* temp;
        int pos, i;
        printf("Enter the position: \n");
        scanf("%d", &pos);
        if(pos==1){
            deletebeg();
        }
        else{
            temp = start;
            for(i=1;i<pos;i++){
                temp = temp->right;
                if(temp==NULL){
                    printf("There are less than %d elements in the list\n", pos);
                    return;
                }
            }
            temp->left->right = temp->right;
            if(temp->right!=NULL){
                temp->right->left = temp->left;
            }
            free(temp);
        }
    }
    void display(){
        node* temp;
        if(start==NULL){
            printf("List is empty\n");
        }
        else{
            temp = start;
            while(temp!=NULL){
                printf("%d\t", temp->data);
                temp = temp->right;
            }
        }
    }
    void search(){
        node* temp;
        int item, i=0, flag;
        temp = start;
        if(temp==NULL){
            printf("List is empty\n");
        }
        else{
            printf("Enter the item to be searched: \n");
            scanf("%d", &item);
            while(temp!=NULL){
                if(temp->data==item){
                    printf("Item found at location %d\n", i+1);
                    flag = 0;
                    break;
                }
                else{
                    flag = 1;
                }
                i++;
                temp = temp->right;
            }
            if(flag==1){
                printf("Item not found\n");
            }
        }
    }
    void reverse(){
        node* temp;
        temp = start;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        printf("Reverse: \n");
        while(temp!=NULL){
            printf("%d\t", temp->data);
            temp = temp->left;
        }
    }
    void main(){
        int n, ch;
        printf("Enter the number of nodes: \n");
        scanf("%d", &n);
        createlist(n);
        while(1){
            printf("\n1. Insert at beginning\n");
            printf("2. Insert at end\n");
            printf("3. Insert at a position\n");
            printf("4. Delete at beginning\n");
            printf("5. Delete at end\n");
            printf("6. Delete at a position\n");
            printf("7. Display\n");
            printf("8. Search\n");
            printf("9. Reverse\n");
            printf("10. Exit\n");
            printf("Enter your choice: \n");
            scanf("%d", &ch);
            switch(ch){
                case 1: inserbeg(n);
                        break;
                case 2: inserend(n);
                        break;
                case 3: insertpos(n);
                        break;
                case 4: deletebeg();
                        break;
                case 5: deleteend();
                        break;
                case 6: deletepos();
                        break;
                case 7: display();
                        break;
                case 8: search();
                        break;
                case 9: reverse();
                        break;
                case 10: exit(0);
                default: printf("Invalid choice\n");
            }
        }
    }



