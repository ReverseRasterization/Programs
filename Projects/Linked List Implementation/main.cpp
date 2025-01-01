#include <iostream>

#include "LinkedList.h"

int main(){
    LinkedList<int> linkedList;

    for (int i = 1; i <= 5; i++){
         linkedList.insertAtBeginning(i);
    } 

    Node<int>* currNode = linkedList.head.get();

    int sum = 0;
    while (currNode != nullptr){
        sum+=currNode->data;
        currNode = currNode->next.get();
    }

    std::cout << "The sum of the linked list is: " << sum;



    linkedList.Display(true);

    return 0;
}