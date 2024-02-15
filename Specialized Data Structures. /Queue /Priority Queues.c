#include <stdio.h>
#include <stdlib.h> 

#define SIZE 5

int items[SIZE];
int n = 0;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int data) {
    if(n == SIZE) {
        printf("\nQueue is full");
        return;
    }
    items[n++] = data;
    int child = n - 1;
    int parent = (child - 1) / 2;
    while(parent >= 0 && items[parent] < items[child]) {
        swap(&items[parent], &items[child]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

int delete() {
    if(n == 0) {
        printf("\nQueue is empty");
        return -1;
    }
    int highestPriority = items[0];
    items[0] = items[--n];
    int parent = 0;
    while(1) {
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;
        int largest = parent;
        if(leftChild < n && items[leftChild] > items[largest])
            largest = leftChild;
        if(rightChild < n && items[rightChild] > items[largest])
            largest = rightChild;
        if(largest != parent) {
            swap(&items[parent], &items[largest]);
            parent = largest;
        } else {
            break;
        }
    }
    return highestPriority;
}

int main() {
    insert(3);
    insert(5);
    insert(1);
    insert(2);
    insert(6);

    for(int i = 0; i < SIZE; i++) {
        printf("%d ", delete());
    }

    return 0;
}
