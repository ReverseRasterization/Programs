#include <iostream>

int factorial(int num);

int main()
{
    // Recursion = a function invokes itself from within
    // breaks a complex concept into a repeatable single step

    // advantage = less code & cleaner, useful for sorting and searching algorithms
    // disadvantages = uses more memory & slower

    std::cout << factorial(10);    

    return 0;
}

int factorial(int num){
    if (num > 1){
        return num * factorial(num - 1);
    }else {
        return 1;
    }
}

