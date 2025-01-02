#include <iostream>
#include <memory>
#include "LinkedList.h"


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
            nNode->next = previousNode->next;
            previousNode->next = nNode;
        }
       
    }
}

// template <typename T>
// void LinkedList<T>::deleteFromBeginning(){
//     if(head) {
//         head = std::move(head->next);
//     }
// }


// template <typename T>
// void LinkedList<T>::deleteFromEnd(){
//     if (!head) {
//         return;
//     }

//     if(head->next == nullptr) {
//         head.reset();
//     }
    
//     Node<T>* secondLastNode = findNodeFromPosition(-2);
//     secondLastNode->next.reset();
// }

// template <typename T>
// void LinkedList<T>::deleteFromPosition(int index){
//     if (!head){ // there's not even a head (overly circumsized)
//         return;
//     }
    
//     if (index == 0) {
//         if (head->next == nullptr){
//             head.reset();
//         }else {
//             head = std::move(head->next);
//         }
        
//         return;
//     }

//     if (index == 1 && head->next == nullptr) { // there's a head, but nothing after (its been circumsized)
//         return;
//     }


//     Node<T>* prevNode = findNodeFromPosition(index-1);
//     if (prevNode!=nullptr && prevNode->next != nullptr){
//         prevNode->next = std::move(prevNode->next->next);
//     }

// }

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
