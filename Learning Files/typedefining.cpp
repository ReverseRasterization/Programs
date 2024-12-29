#include <iostream>
#include <vector>

//typedef std::vector<std::pair<std::string, int>> pairlist_t;
//typedef std::string text_t;
//typedef int number_t;

using text_t = std::string;
using number_t = int; 

int main(){

    //pairlist_t pairlist;
    text_t message {"Hello, world!"};
    number_t age = 21;

    std::cout << message << '\n'; 
    std::cout << age << '\n';


    return 0;
}