#include <iostream>

void displayArray(std::string array[], int size);

int main()
{
    std::string cars[] = {"Corevette", "Mustang", "Camry"}; // by default, outputs memory address
    cars[0] = "Subaru";

    int size = sizeof(cars)/sizeof(std::string);
    
    displayArray(cars, size);

    std::string foods[100];

    fill(foods, foods + 100, "pizza");

    for (std::string food : foods){
        std::cout << food << '\n';
    }

    return 0;
}

void displayArray(std::string array[], int size) // size is required to iterate through the array because whenever a list is passed onto a parameter, it's decayed into a pointer so it looses the size awareness
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << '\n';
    }
}