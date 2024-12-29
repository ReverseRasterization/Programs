#include <iostream>

void happyBirthday(std::string Name, int age);

int main()
{
    happyBirthday("Zachary", 18);
    return 0;
}

void happyBirthday(std::string Name, int age){
    std::cout << "Happy birthday " << Name << "! You are now " << age << " years old!";
}