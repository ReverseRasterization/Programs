#include <iostream>

#include "LinkedList.h"

// TODO: In singly linked, if someone requests to insert something and theres no head and the index isnt 0, just cancel the operation
// TODO: Add errors in insert at position, all delete functions, and find node from position for both singly and doubly

// TODO: For doubly, if the user is trying to insert at the end using the position insert function then fix the no previous bug

int main(){
    // SLinkedList<int> singlyLinkedList;

    // for (int i = 1; i <= 5; i++){
    //      singlyLinkedList.insertAtBeginning(i);
    // } 

    // Node<int>* currNode = singlyLinkedList.head.get();

    // int sum = 0;
    // while (currNode != nullptr){
    //     sum+=currNode->data;
    //     currNode = currNode->next.get();
    // }

    // std::cout << "The sum of the linked list is: " << sum;



    // singlyLinkedList.Display(true);

    LinkedList<int> dLinkedList(true);
    for (int i = 1; i <= 5; i++){
        dLinkedList.insertAtBeginning(i);
    } 

    dLinkedList.insertAtPosition(6, 69);

    dLinkedList.Display(true);

    return 0;
}