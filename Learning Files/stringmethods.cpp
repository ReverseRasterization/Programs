#include <iostream>

int main()
{
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    /*
    name.clear();
    name.append("@gmail.com");
    name.at(0); // the character at i position
    name.insert(0, "@") // index, string2
    name.find(' '); // gets the position of the parameter in the string
    name.erase(0, 3); // elimiates the first 3 characters
    */

    if (name.empty()) {
        std::cout << "You didnt enter your name";
    }else if (name.length() > 12){
        std::cout << "Your name cannot be over 12 characters";
    }else {
        std::cout << "Welcome " << name;
    }

}