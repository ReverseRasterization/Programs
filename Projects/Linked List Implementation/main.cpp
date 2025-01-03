#include <iostream>
#include <memory>

#include "LinkedList.h"

int main(){
    LinkedList<int> dLinkedList(true);
    
    for (int i = 1; i <= 5; i++){
        dLinkedList.insertAtBeginning(i);
    } 

    dLinkedList.Display(true);

    return 0;
}