// Practice program that allows a user to withdraw, deposit, and view their balance

#include <iostream>

void showBalance(double balance);
int displayMenu();
double deposit();
double withdraw(double balance);

int main()
{
    double balance {0.0};
    bool running = true;

    while (running){
        int choice = displayMenu();

        switch(choice){
            case 1: showBalance(balance);
                break;
            case 2: balance+=deposit();
                break;
            case 3: balance-=withdraw(balance);
                break;
            case 4: 
                std::cout << "\nGoodbye!";
                running = false;
                break;
            default:
                std::cout << "\nInvalid input. Please input a number (1-4)";
                break;
        }
    }

    return 0;
}

void showBalance(double balance)
{
    std::cout << "\nYour balance is: " << balance;
}

int displayMenu()
{
    std::cout << "\n\nWelcome user! Please input your intent:\n";
    std::cout << "  [1] - View Balance\n";
    std::cout << "  [2] - Deposit Money\n";
    std::cout << "  [3] - Withdraw Money\n";
    std::cout << "  [4] - Exit\n";
    std::cout << "> ";

    int choice;
    std::cin >> choice;

    return choice;
}

double deposit()
{
    int x;

    std::cout << "\nHow much would you like to deposit into your account?" << '\n' << "> ";
    std::cin >> x;

    return x;
}

double withdraw(double balance)
{
    int amount;

    std::cout << "\nHow much would you like to withdraw from your account?" << '\n' << "> ";
    std::cin >> amount;

    if (balance < amount){ // insufficient funds
        std::cout << "Insufficient funds.";
        return 0.0;
    }else {
        return amount;
    }
}

