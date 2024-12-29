#include <iostream>

int main()
{
    // Dynamic memory is memory allocated after the program is already compiled and running. 
    // Uses the 'new' operator to allocate memory in the heap rather than the stack
    // This is useful when we dont know how much memory we will need. Makes programs more flexible; especially when accepting user input

    // int *pNum {NULL};

    // pNum = new int;

    // *pNum = 21;

    // std::cout << "Address: " << pNum << '\n';
    // std::cout << "Value: " << *pNum << '\n';

    // delete pNum;

    char *pGrades = NULL;
    int size;

    std::cout << "How many grades to enter in?: ";
    std::cin >> size;

    pGrades = new char[size];

    for (int i = 0; i < size; i++){
        std::cout << "\nEnter grade #" << i + 1 << ": ";
        std::cin >> pGrades[i];
    }

    for (int i = 0; i < size; i++){
        std::cout << pGrades[i] << " ";
    }

    delete[] pGrades;

    return 0;
}