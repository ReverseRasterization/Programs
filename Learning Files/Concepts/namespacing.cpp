#include <iostream>

namespace first{
    int x = 1;
}

namespace second{
    int x = 2;
}

int main(){

    using namespace first;

    //int x = 0;

    //std::cout << first::x; // prints out 1 (WITHOUT THE using STATEMENT)

    std::cout << x;

    return 0;
}