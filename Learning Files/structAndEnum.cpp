#include <iostream>

enum Day {
    sunday = 0, 
    monday = 1, 
    tuesday = 2, 
    wednesday = 3, 
    thursday = 4, 
    friday = 5, 
    saturday = 6
};

// struct student{
//     std::string name; // member
//     double gpa;
//     bool enrolled = true;
// };

// struct Car {
//     std::string model;
//     int year;
//     std::string color;
// };

// void printCar(Car &car);
// void paintCar(Car &car, std::string color);

int main()
{
    // student student1;
    // student1.name = "Spongebob";
    // student1.gpa = 3.2;

    // std::cout << student1.name << '\n';
    // std::cout << student1.gpa << '\n';
    // std::cout << student1.enrolled << '\n';

    // student student2;
    // student2.name = "Patrick";
    // student2.gpa = 2.1;

    // std::cout << student2.name << '\n';
    // std::cout << student2.gpa << '\n';
    // std::cout << student2.enrolled << '\n';

    // Car car1;
    // Car car2;

    // car1.model = "Mustang";
    // car1.year = 2023;
    // car1.color = "red";

    // car2.model = "Corvette";
    // car2.year = 2024;
    // car2.color = "blue";

    // paintCar(car1, "Silver");

    // printCar(car1);
    // printCar(car2);

    Day today = tuesday;

    switch(today){
        case sunday:
            std::cout << "It's sunday!";
            break;
        case 1:
            std::cout << "It's monday!";
            break;
        default:
            break;
    }

    return 0;
}

// void printCar(Car &car){
//     std::cout << car.model << '\n';
//     std::cout << car.year << '\n';
//     std::cout << car.color << '\n';
// }
// void paintCar(Car &car, std::string color){
//     car.color = color;
// }