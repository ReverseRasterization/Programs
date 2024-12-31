#include <iostream>

#include "LinkedList.h"

int main(){
    LinkedList<std::string> linkedList;

    linkedList.insertAtBeginning("Hola!");
    // for (int i = 1; i <= 5; i++){
    //     linkedList.insertAtBeginning(i);
    // } 

    linkedList.Display(false);

    return 0;
}