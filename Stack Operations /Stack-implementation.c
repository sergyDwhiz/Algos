// Implements a Last In First Out Data Structure in C 
//### Operations: 
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
int top=-1;
int STACK[MAX_SIZE];
void operations()
{
    printf("1. Push (place) an Element into a stack. \n");
    printf("2. Pop an Element into a stack. \n");
    printf("3. Peek. (To return the first element.)  \n");
    printf("4. Check if stack is empty. \n");
    printf("5. Check if Stack is full. \n");
}
bool is_empty(int top) {
    if(top==-1){
        return true;
    }
    else 
    return false;
}
bool is_full(int top) {
    if(top == MAX_SIZE-1){
        return true;
    }
    else 
        return false;
}
void push(int val){
    if(is_full()){
        printf("** Stack Overflow **");
    }
    else 
    val = STACK[]
}


