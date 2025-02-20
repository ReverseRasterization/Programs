#include <iostream>
#include <memory>
#include "SLinkedList.H"


template <typename T>
void SLinkedList<T>::insertAtBeginning(T data)
{
    // Create a new node
    auto nNode = std::make_unique<Node<T>>(data);

    nNode->next = std::move(head);
    head = std::move(nNode);   // Update head to the new node
}

template <typename T>
void SLinkedList<T>::insertAtEnd(T data)
{
    auto nNode = std::make_unique<Node<T>>(data);

    if (!head){
        head = std::move(nNode);
    }else {
        Node<T>* lastNode = findNodeFromPosition(-1);
        lastNode->next = std::move(nNode);
    }
}

template <typename T>
void SLinkedList<T>::insertAtPosition(int index, T data){
    auto nNode = std::make_unique<Node<T>>(data);

    if (!head){
        head = std::move(nNode);
    }else if (index == 0) {
        insertAtBeginning(data);
    }else {
        Node<T>* previousNode = findNodeFromPosition(index-1);
        nNode->next = std::move(previousNode->next);
        previousNode->next = std::move(nNode);
    }
}

template <typename T>
void SLinkedList<T>::deleteFromBeginning(){
    if(head) {
        head = std::move(head->next);
    }
}


template <typename T>
void SLinkedList<T>::deleteFromEnd(){
    if (!head) {
        return;
    }

    if(head->next == nullptr) {
        head.reset();
        return;
    }
    
    Node<T>* secondLastNode = findNodeFromPosition(-2);
    secondLastNode->next.reset();
}

template <typename T>
void SLinkedList<T>::deleteFromPosition(int index){
    if (!head){ // there's not even a head (overly circumsized)
        return;
    }
    
    if (index == 0) {
        if (head->next == nullptr){
            head.reset();
        }else {
            head = std::move(head->next);
        }
        
        return;
    }


    Node<T>* prevNode = findNodeFromPosition(index-1);
    if (prevNode!=nullptr && prevNode->next != nullptr){
        prevNode->next = std::move(prevNode->next->next);
    }

}

template <typename T>
void SLinkedList<T>::Display(bool debug)
{
    Node<T>* currNode = head.get();

    int i = 0;
    while(currNode != nullptr){
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
Node<T>* SLinkedList<T>::findNodeFromPosition(int index)
{
    Node<T>* currNode = head.get();

    if (index == -1){ // Find the end
        while(currNode && currNode->next){
            currNode = currNode->next.get();
        }
    }else if (index == -2) { // Find the 2nd to last node
        while(currNode && currNode -> next && currNode->next->next){
            currNode = currNode->next.get();
        }
        
    }else {
        for (int i = 0; i < index && currNode; i++){
            currNode = currNode->next.get();
        }
    }

    return currNode;
}

template class SLinkedList<int>;
template class SLinkedList<double>;
template class SLinkedList<float>;
template class SLinkedList<char>;
template class SLinkedList<std::string>;
