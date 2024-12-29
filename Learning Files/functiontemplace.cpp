#include <iostream>
template <typename T, typename U> // allows for up to 2 different datatypes

auto max(T x, U y){ // T being "thing"
    return (x > y) ? x : y;
}

int main()
{
    // Function template = describes what a function looks like. Can be used to generate as many overloaded functions as needed, each using different data types

    std::cout << max(1,2.1) << '\n';
    // std::cout << max(1.1,2.1) << '\n';
    // std::cout << max('1','2') << '\n';

    return 0;
}


