#include <iostream>

int main()
{
    char op;
    double num1, num2, result;

    std::cout << "Enter either (+ - * /): ";
    std::cin >> op;

    std::cout << "Enter num1: ";
    std::cin >> num1;

    std::cout << "Enter num2: ";
    std::cin >> num2;

    switch(op){
        case '+':
            result = num1+num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '-':
            result = num1-num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '*':
            result = num1*num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '/':
            result = num1/num2;
            std::cout << "Result: " << result << '\n';
            break;
        default:
            std::cout << "Invalid operator";
            break;
    }

    return 0;
}