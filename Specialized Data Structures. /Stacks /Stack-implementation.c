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
bool is_empty() {
    if(top==-1){
        return true;
    }
    else 
    return false;
}
bool is_full() {
    if(top == MAX_SIZE-1){
        return true;
    }
    else 
        return false;
}
void push(int val){
    if(is_full(top)){
        printf("** Stack Overflow ** \n Cannot push %d into the stack. \n", val);
    }
    else {
        top++;
        STACK[top] = val;
    }
}
int pop(){
    int val;
    if(is_empty(top)){
        printf("** Stack Underflow ** \n Cannot pop %d into the stack. \n", val);
    }
        val = STACK[top];
        top--;
        printf("Popped item %d from the stack.\n", val);
        return val;
}
void peek() {
    if (is_empty(top)) {
        printf("Stack Underflow. Cannot peel item.\n");
    } else {
        printf("Peeking item %d from the stack.\n", STACK[top]);
    }
}
int main(void){
   /* Unit Test variables. */
//  int top = -1;
//     int stack[10];
    int choice;
    int val;
    printf("Enter your choice:\n ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the value to be pushed:\n ");
        scanf("%d", &val);
        push(val);
        break;
//     Test push function
//     push(stack, &top, 5);
//     assert(stack[top] == 5); 
    
    case 2:
        pop(); 
        break;
//     Test pop function
//     int val = pop(stack, &top);
//     assert(val == 5);
    case 3: 
        peek();
        break;
// No peek test case :)
    case 4: 
        if(is_empty(top)){
            printf("Stack is empty\n");
        } 
        else{
            printf("Stack is not empty\n");
        }
        break;
//     Test is_empty function
//     assert(is_empty(top) == 1);

    case 5: 
        if(is_full(top)){
            printf("Stack is Full");
        }
        else{
            printf("Stack is not full\n");
        }
        break;
//     Test is_full function
//     assert(is_full(top) == 0);
    default:
    break; 
    } 
    
// printf("All tests passed successfully!\n");
  return 0;
}

