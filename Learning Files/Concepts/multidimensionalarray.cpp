#include <iostream>

int main(){
    std::string cars[][3] = {{"Mustang", "Escape", "F-150"},
                            {"Corvette", "Equinox", "Silverado"},
                            {"Challenger", "Durango", "Ram 1500"}};

    // std::cout << cars[0][0] << ' ';
    // std::cout << cars[0][1] << ' ';
    // std::cout << cars[0][2] << ' ';

    int rows = sizeof(cars) / sizeof(cars[0]);
    int columns = sizeof(cars[0]) / sizeof(cars[0][0]);

    for (int i = 0; i < rows; i++){
        // std::cout << cars[i] << '\n'; // rows

        for (int j = 0; j < columns; j++){
            std::cout << cars[i][j] << " ";
        }

        std::cout << '\n';
        
    }
}