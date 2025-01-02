#ifndef LINKEDLIST_S
#define LINKEDLIST_S

#include <memory>

template <typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> next;

    void display() {
        std::cout << "Data: " << data << '\n';
        std::cout << "Next: " << next.get() << "\n"; 
    }

    Node(T value):data(value), next(nullptr){}
};

template <typename T>
class SLinkedList 
{
    public:
        std::unique_ptr<Node<T>> head = nullptr;

        void insertAtBeginning(T data);
        void insertAtEnd(T data);
        void insertAtPosition(int index, T data);
        void deleteFromBeginning();
        void deleteFromEnd();
        void deleteFromPosition(int index);
        void Display(bool debug);

        Node<T>* findNodeFromPosition(int index);
};



#endif