#include <iostream>
#include "LinkedList.h"


template <typename T>
void LinkedList<T>::insertAtBeginning(T data)
{
    // Create a new node
    Node<T>* nNode = new Node<T>(data);

    nNode->next = head;
    head = nNode;   // Update head to the new node
}

template <typename T>
void LinkedList<T>::insertAtEnd(T data)
{
    Node<T>* nNode = new Node<T>(data);

    if (!head){
        head = nNode;
    }else {
        Node<T>* lastNode = findNodeFromPosition(-1);
        lastNode->next = nNode;
    }
}

template <typename T>
void LinkedList<T>::insertAtPosition(int index, T data){
    Node<T>* nNode = new Node<T>(data);

    if (!head){
        head = nNode;
    }else {
        Node<T>* previousNode = findNodeFromPosition(index-1);
        nNode->next = previousNode->next;
        previousNode->next = nNode;
    }
}

template <typename T>
void LinkedList<T>::deleteFromBeginning(){
    if(head) {
        head = head->next;
    }
}

template <typename T>
void LinkedList<T>::deleteFromEnd(){
    if (!head) {
        return;
    }

    if(head->next == nullptr) {
        head = nullptr;
    }
    
    Node<T>* secondLastNode = findNodeFromPosition(-2);
    secondLastNode->next = nullptr;
}

template <typename T>
void LinkedList<T>::deleteFromPosition(int index){
    if (!head){ // there's not even a head (overly circumsized)
        return;
    }
    
    if (index == 0) {
        if (head->next == nullptr){
            head = nullptr;
        }else {
            head = head->next;
        }
        
        return;
    }

    if (index == 1 && head->next == nullptr) { // there's a head, but nothing after (its been circumsized)
        return;
    }


    Node<T>* prevNode = findNodeFromPosition(index-1);
    if (prevNode!=nullptr && prevNode->next != nullptr){
        prevNode->next = prevNode->next->next;
    }

}

template <typename T>
void LinkedList<T>::Display(bool debug)
{
    Node<T>* currNode = head;

    int i = 0;
    while(currNode != nullptr){
        if (debug) {
            std::cout << '(' << i << ")\n";
            currNode->display();
            i++;
        }else {
            std::cout << currNode->data << ' ';
        }

        currNode = currNode->next;
    }
}

template <typename T>
Node<T>* LinkedList<T>::findNodeFromPosition(int index)
{
    Node<T>* currNode = head;

    if (index == -1){ // Find the end
        while(currNode->next != nullptr){
            currNode = currNode->next;
        }
    }else if (index == -2) { // Find the 2nd to last node
        while(currNode->next->next != nullptr){
            currNode = currNode->next;
        }
        
    }else {
        for (int i = 0; i < index; i++){
            if (currNode->next != nullptr){
                currNode = currNode->next;
            }else {
                currNode = nullptr;
                break;
            }
        }
    }

    return currNode;
}

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<float>;
template class LinkedList<std::string>;



