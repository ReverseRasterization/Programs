#include <iostream>
#include <ctime>

int main()
{
    srand(time(NULL));

    int num {(rand() % 100) + 1};
    int guess;
    int tries;

    while (guess != num)
    {
        std::cout << "Guess the number: ";
        std::cin >> guess;

        if (guess > num){
            std::cout << "Lower!" << '\n';
        }else if (guess < num){
            std::cout << "Higher!" << '\n';
        }

        tries+=1;
    }

    std::cout << "Congrats! You guessed the number correctly in " << tries << " tries!";


    return 0;
}