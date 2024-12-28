#include <iostream>

/*
    LUHN ALGORITHM:
        1. Double every second digit from right to left
        2. Add all single digits from step 1
        3. Add all odd numbered digits from right to left
        4. Sum Results from 2 & 3
        5. If step 4 is divisible by 10, the number is valid
*/

int getDigit(const int number);
int sumOdd(const std::string cardNumber);
int sumEven(const std::string cardNumber);

int main()
{
    std::string cardNumber;
    int result = 0;

    std::cout << "Enter a credit card #: ";
    std::cin >> cardNumber;

    result = sumEven(cardNumber) + sumOdd(cardNumber);

    std::cout << result;

    if (result % 10 == 0){
        std::cout << "Valid!";
    }else {
        std::cout << "Not Valid!";
    }

    return 0;
}

int getDigit(const int number)
{
    // 18 > 8             18/10 > 1 % 10 > 1                 8 + 1 = 9
    return number % 10 + (number/10 % 10);
}

int sumOdd(const std::string cardNumber)
{
    int sum;

    for(int i = cardNumber.size() - 1; i >= 0; i-=2)
    {
        sum+=cardNumber[i] - '0';
    }   

    return sum;
}

int sumEven(const std::string cardNumber)
{
    int sum;

    for(int i = cardNumber.size() - 2; i >= 0; i-=2)
    {
        sum+=getDigit((cardNumber[i] - '0') * 2);
    }   

    return sum;
}