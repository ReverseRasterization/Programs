#include <iostream>
#include <memory>

#include "LinkedList.h"


// TODO: In singly linked, if someone requests to insert something and theres no head and the index isnt 0, just cancel the operation
// TODO: singly linked: fix the delete from end function, my dumbass forgot a return in the nothing after head statement
// TODO: Add errors in insert at position, all delete functions, and find node from position for both singly and doubly


int main(){
    LinkedList<int> dLinkedList(true);
    
    for (int i = 1; i <= 5; i++){
        dLinkedList.insertAtBeginning(i);
    } 

    std::weak_ptr<Node<int>> ptr1 = dLinkedList.head;    
    std::weak_ptr<Node<int>> ptr2 = ptr1.lock()->next;
    std::weak_ptr<Node<int>> ptr3 = ptr2.lock()->next;
    std::weak_ptr<Node<int>> ptr4 = ptr3.lock()->next;
    std::weak_ptr<Node<int>> ptr5 = ptr4.lock()->next;

    dLinkedList.deleteFromEnd();

    std::cout << "Ptr1: " << ptr1.lock()->data << '\n';
    std::cout << "Ptr2: " << ptr2.lock()->data << '\n';
    std::cout << "Ptr3: " << ptr3.lock()->data << '\n';
    std::cout << "Ptr4: " << ptr4.lock()->data << '\n';
    std::cout << "Ptr5: " << ptr5.lock()->data << '\n';


    return 0;
}