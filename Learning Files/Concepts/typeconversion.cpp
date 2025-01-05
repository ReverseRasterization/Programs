#include <iostream>

int main(){
    // Implicit = automatic conversion
    // Explicit = Precede value with new data type

    double x {(int) 3.14}; // 3
    //char x {100}; // d
    int y {(char) 'd'}; // 100

    int correct = 8;
    int questions = 10;

    double score {correct/(double)questions * 100};

    std::cout << score << '%'; 

    return 0;
}