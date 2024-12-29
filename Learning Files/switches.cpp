#include <iostream>

int main()
{
    int month;

    std::cout << "Enter the month (1-12): ";
    std::cin >> month;

    
    switch(month){
        case 1:
            std::cout << "It is january!";
            break;
        case 2:
            std::cout << "It is febuary!";
            break;
        case 3:
            std::cout << "It is march!";
            break;
        case 4:
            std::cout << "It is april!";
            break;
        case 5:
            std::cout << "It is may!";
            break;
        case 6:
            std::cout << "It is june!";
            break;
        case 7:
            std::cout << "It is july!";
            break;
        case 8:
            std::cout << "It is august!";
            break;
        case 9:
            std::cout << "It is september!";
            break;
        case 10:
            std::cout << "It is october!";
            break;
        case 11:
            std::cout << "It is november!";
            break;
        case 12:
            std::cout << "It is december!";
            break;  
        default:
            std::cout << "Please enter in only numbers (1-12)";
            break;  
    }
    

    return 0;
}