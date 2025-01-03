#ifndef LINKEDLIST
#define LINKEDLIST

#include <memory>
#include <iostream>

template <typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;
    
    void display() {
        std::cout << "Previous " << prev.lock().get() << '\n';
        std::cout << "Data: " << data << '\n';
        std::cout << "This: " << this << '\n';
        std::cout << "Next: " << next.get() << "\n"; 
    }

    Node(T value):data(value), next(nullptr), prev(){}
};

template <typename T>
class LinkedList 
{
    public:
        bool looped = false;

        std::shared_ptr<Node<T>> head = nullptr;

        void insertAtBeginning(T data);
        void insertAtEnd(T data);
        void insertAtPosition(int index, T data);
        void deleteFromBeginning();
        void deleteFromEnd();
        void deleteFromPosition(int index);
        void Display(bool debug);

        std::weak_ptr<Node<T>> findNodeFromPosition(int index);

        LinkedList(bool looped){
            this->looped = looped;
        }
};



#endif