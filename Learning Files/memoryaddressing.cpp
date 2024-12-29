#include <iostream>

// void swap(std::string &x, std::string &y);

int main()
{
    // // memory address = a location in memory where data is stored
    // // a memory address can be accessed with & (address-of operator)

    // std::string name = "Zach";
    // int age = 21;
    // bool student = true;

    // std::cout << &name << '\n'; // 0xfea0fff950 = 1093622823248
    // std::cout << &age << '\n'; // 0xfea0fff94c = 1093622823244 // strings take up 4 bytes; hence, 1093622823248 - 1093622823244 = 4
    // std::cout << &student << '\n'; // 0xfea0fff94b = 1093622823243

    // // Passing by reference

    // std::string x {"Kool-Aid"};
    // std::string y {"Water"};

    // swap(x,y);

    // std::cout << "X: " << x << '\n';
    // std::cout << "Y: " << y << '\n';

    // Pointers = variable that stores a memory address of another variable
    //            sometimes it's easier to work with an address

    // & address-of operator
    // * dereference operator

    // std::string name {"Zach"};
    // int age = 17;
    // std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4"};

    // std::string *pName {&name};
    // int *pAge {&age};
    // std::string *pfreePizzas = freePizzas; // arrays is already a memory address
    

    // std::cout << *pName << '\n';
    // std::cout << *pAge << '\n';
    // std::cout << *pfreePizzas << '\n';

    // nullptrs are helpful if determining if an address was successfully assigned to a pointer

    int *pointer {nullptr};
    int x {123};

    pointer = &x;

    if (pointer == nullptr) {
        std::cout << "Address was not assigned!\n";
        //std::cout << *pointer; // dont do this...
    }else {
        std::cout << "Address was assigned!\n";
        std::cout << *pointer;
    }

    return 0;
}

// void swap(std::string &x, std::string &y){
//     std::string temp;

//     temp = x;
//     x = y;
//     y = temp;
// }