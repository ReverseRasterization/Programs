#ifndef LINKEDLIST
#define LINKEDLIST

template <typename T>
struct Node {
    T data;
    Node* next;

    void display();

    Node(T value):data(value), next(nullptr){}
};

template <typename T>
class LinkedList 
{
    public:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;

        void insertAtBeginning(T data);
        void insertAtEnd(T data);
        void insertAtPosition(int index, T data);
        void deleteFromBeginning();
        void deleteFromEnd();
        void deleteFromPosition(int index);
        void Display(bool debug);

    private:
        Node<T>* findNodeFromPosition(int index);
};

template <typename T>
void Node<T>::display() {
    std::cout << "Data: " << data << '\n';
    std::cout << "Next: " << next << "\n\n"; 
}

#endif