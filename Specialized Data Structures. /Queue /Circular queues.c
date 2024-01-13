#include <stdio.h>
#define SIZE 5

//Declare Queue  variables to track status. 
int items[SIZE];
int front = -1, rear =-1, count = 0;

//Check is Queue is full
int isFull() { 
    if(count == SIZE) return 1;
    return 0;
}

//Check if Queue is empty
int isEmpty() {
    if(count == 0) return 1;
    return 0;
}

//Add an element to the queue `[O(1)]`
void enQueue(int element) {
    if(isFull()) printf("\n Queue is full!! \n");
    else {
        if(front == -1) front = 0; //If Queue is empty, set front to the first position. 
        rear = (rear + 1) % SIZE;  // Move the Rear to next position, ready for addition.
        items[rear] = element;  // Add the element at the rear.
        count++;   // You just had a new element, so Incresase the count.
        printf("\n Inserted -> %d", element);
    }
}

//Remove an element from the Queue `[O(1)]`
int deQueue() {
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front]; // Get the element at the front.
        if (front == rear){ //If there is only one element in the queue, reset the queue after deleting it.
            front = -1;    // By resetting the front and rear to -1.
            rear = -1;
        } /* Q has only one element, so we reset the queue after deleting it. */
        else {
            front = (front + 1) % SIZE; // Move the front to the next position.
            
        }
        count--; // You just had an element removed, so decrease the count.
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}

void display() {
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {  // Loop from front to rear, using the modulo operator to get the next position.
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}
