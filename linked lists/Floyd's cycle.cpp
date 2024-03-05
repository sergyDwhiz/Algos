/*
 Detects cycles in a linked list.
 Uses two pointers, one moving at twice(the hare) the
 speed of the other (the tortoise), to detect a cycle in a linked list.
*/

#include<iostream>
using namespace std

struct Node{
    int data;
    Node* next;
};

// List with less than 2 elements can't have a cycle
bool hasCycle(Node* head){
    if(head == nullptr || head -> next == nullptr){
    return false; // No cyle
    }

Node* slow = head;
Node* fast = head-> next;

//Loop until both ptrs meet, indicating a cycle.
while (slow != fast){
    if(fast == nullptr || fast-> next == nullptr){
        return false; // No cycle, if we've reach the end of the List.
    }

    slow = slow-> next;
    fast = fast-> next->next;
}

  return true;
}

int main(){
    // Test case
    Node* head = new Node();
    head->data =1;

    Node* second = new Node();
    second->data = 2;
    head->next = second;

    Node* third = new Node();
    third->data = 2;
    head->next = third;

    //Test cycle
    third->next = second;

    if(hasCycle(head)){
        cout << "Cycle detected" << endl;
    } else{
        cout << "No cycle detected" <<endl;
    }

    return 0;
}


