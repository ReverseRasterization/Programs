// Rock paper scissors
// 1: Rock
// 2: Paper
// 3: Scissors
// 4: Quit

#include <iostream>
#include <ctime>

int getUserChoice();
int getComputerChoice();
std::string whoWon(int userChoice, int computerChoice);

int main()
{
    srand(time(NULL));

    bool playing = true;

    while(playing)
    {
        int userChoice = getUserChoice();

        if (userChoice == 4){
            std::cout << "\nGoodbye!";
            break;
        }

        int computerChoice = getComputerChoice();

        switch (computerChoice)
        {
            case 1: std::cout << "\nThe computer chose rock"; break;
            case 2: std::cout << "\nThe computer chose paper"; break;
            case 3: std::cout << "\nThe computer chose scissors"; break;
        }
        

        std::cout << '\n' << whoWon(userChoice, computerChoice) << '\n';
    } 

    return 0;
}

int getUserChoice()
{
    int choice = -1;
    
    while(choice == -1)
    {
        std::cout << "\nWhat would you like to play?\n";
        std::cout << "  [1] - Rock\n";
        std::cout << "  [2] - Paper\n";
        std::cout << "  [3] - Scissors\n";
        std::cout << "  [4] - Quit\n";
        std::cout << "> ";

        std::cin >> choice;

        if (choice < 1 || choice > 4){
            std::cout << "\nInvalid input, please input a number (1-4)\n";
            choice = -1;
        }
    }
    
    return choice;

}

int getComputerChoice()
{
    return rand() % 3 + 1;
}

std::string whoWon(int userChoice, int computerChoice){
    

    if (userChoice == computerChoice){
        return "Tie!";
    }

    std::string retVal;

    switch(userChoice){
        case 1: // rock
            if (computerChoice == 2){ // Paper
                retVal = "Computer Won!";
            }else { // Scissors
                retVal = "User Won!";
            }
            break;
        case 2: // Paper
            if (computerChoice == 1){ // Rock
                retVal = "User Won!";
            }else { // Scissors
                retVal = "Computer Won!";
            }
            break;
        case 3: // Scissors
            if (computerChoice == 1){ // Rock
                retVal = "Computer Won!";
            }else { // Paper
                retVal = "User Won!";
            }
            break;
    }

    return retVal;
}