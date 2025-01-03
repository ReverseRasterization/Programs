
#include "LinkedList.h"

#include <iostream>
#include <memory>




template <typename T>
void LinkedList<T>::insertAtBeginning(T data)
{
    // Create a new node
    auto nNode = std::make_shared<Node<T>>(data);

    // Update the tails next value if necessary and the nodes previous value
    if (looped && head){
        auto tail = head->prev.lock();

        if (tail){
            nNode->prev = tail;
            tail->next = nNode;
        }else if(!tail && head) { // there's abt to be 2 elements now
            nNode->prev = head;
        }

        nNode->next = head;
        head->prev = nNode;
        
    }else if (head) {
        nNode->next = head;
        head->prev = nNode;
    }

    head = nNode;
}

template <typename T>
void LinkedList<T>::insertAtEnd(T data)
{
    auto nNode = std::make_shared<Node<T>>(data);

    if (!head){
        head = nNode;
    }else if (!head->next) { // isnt a second value
        head->next = nNode;
        nNode->prev = head;

        if (looped){
            head->prev = nNode;
            nNode->next = head;
        }
    }else {

        if (looped){
            auto tail = head->prev.lock();
            tail->next = nNode;
            nNode->prev = tail;
            nNode->next = head;

            head->prev = nNode;
        }else {
            std::shared_ptr<Node<T>> tail = findNodeFromPosition(-1).lock();

            tail->next = nNode;
            nNode->prev = tail;
        }

        
        
    }
}

template <typename T>
void LinkedList<T>::insertAtPosition(int index, T data){
    auto nNode = std::make_shared<Node<T>>(data);

    if (!head && index != 0){
        return;
    }else if (index == 0) {
        insertAtBeginning(data);
    }else {
        std::shared_ptr<Node<T>> previousNode = findNodeFromPosition(index-1).lock();
        if (previousNode) {
            nNode->prev = previousNode;
            nNode->next = previousNode->next;
            previousNode->next = nNode;
        }
       
    }
}

template <typename T>
void LinkedList<T>::deleteFromBeginning(){
    if(head) {
        if (!head->prev.expired()){
            head->prev.lock()->next = head->next; // this just sets the tails next value to the heads next value

            if (head->next){
                head->next->prev = head->prev; // this just sets the new heads previous value to the tail assuming looping
            }
        }

        if (head->next && !looped){
            head->next->prev.reset(); // this gets rid of the previous value of the node after the head assuming no looping
        }
        
        head = head->next;
    }
}


template <typename T>
void LinkedList<T>::deleteFromEnd(){
    if (!head) {
        return;
    }

    if(!head->next) {
        head = nullptr;
        return;
    }

    if (looped){
        if (head->prev.lock()->prev.lock() != head){ 
            head->prev = head->prev.lock()->prev;
            head->prev.lock()->next = head;
        }else { // the list only has 2 elements
            head->next = nullptr;
            head->prev.reset();
        }
        
    }else {
        std::shared_ptr<Node<T>> secondLastNode = findNodeFromPosition(-2).lock();
        if (secondLastNode){
            secondLastNode->next.reset();
        }
        
    }
    
    
}

template <typename T>
void LinkedList<T>::deleteFromPosition(int index){
    if (!head){ // there's not even a head
        return;
    }
    
    if (index == 0) { // delete the head
        deleteFromBeginning();
        
        return;
    }

    // if (index == 1 && head->next == nullptr) { // there's a head, but nothing after (its been circumsized)
    //     return;
    // }


    std::shared_ptr<Node<T>> prevNode = findNodeFromPosition(index-1).lock();
    if (prevNode && prevNode->next){
        auto targetNode = prevNode->next;

        prevNode->next = targetNode->next;
        prevNode->next->prev = prevNode;
        
    }

}

template <typename T>
void LinkedList<T>::Display(bool debug)
{
    Node<T>* currNode = head.get();

    int headCount = 0;

    int i = 0;
    while(currNode != nullptr){
        if (looped && currNode == head.get()){headCount++;};
        if (looped && headCount == 2){break;}
        if (debug) {
            std::cout << "\n(" << i << ")\n";
            currNode->display();
            i++;
        }else {
            std::cout << currNode->data << ' ';
        }

        currNode = currNode->next.get();
    }
}

template <typename T>
std::weak_ptr<Node<T>> LinkedList<T>::findNodeFromPosition(int index)
{
    std::shared_ptr<Node<T>> currNode = head;

    if (index == -1){ // Find the end
        while(currNode && currNode->next){
            currNode = currNode->next;
        }
    }else if (index == -2) { // Find the 2nd to last node
        while(currNode && currNode -> next && currNode->next->next){
            currNode = currNode->next;
        }
        
    }else {
        for (int i = 0; i < index && currNode; i++){
            currNode = currNode->next;
        }
    }

    return currNode;
}

template class LinkedList<int>;
// template class LinkedList<double>;
// template class LinkedList<float>;
// template class LinkedList<char>;
// template class LinkedList<std::string>;
