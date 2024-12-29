#include <iostream>

class Human {
    public:
        std::string name {"Rick"};
        std::string occupation {"Scientist"};
        int age {70};

        void eat(){
            std::cout << "This person is eating\n";
        }

        void drink(){
            std::cout << "This person is drinking\n";
        }

        void sleep(){
            std::cout << "This person is sleeping\n";
        }

    Human(std::string name, std::string occupation, int age){ // you may also overload constructors
        this->name = name; // you can also just use name = name;
        this->occupation = occupation;
        this->age = age;
    }
};

class Stove{
    private:
        int temperature = 0;

    

    public:
        
        int getTemperature(){
            return temperature;
        }

        void setTemperature(int temp){
            this->temperature = temp;
        }

        Stove(int temp){
            setTemperature(temp);
        }


};

class Animal {
    public:
        bool alive = true;

        void eat(){
            std::cout << "This animal is eating\n";
        }
};

class Dog : public Animal {
    public:
        void bark(){
            std::cout << "The dog goes woof!\n";
        }
};

class Cat : public Animal {
    public:
        void meow(){
            std::cout << "The cat goes meow!\n";
        }
};

int main(){

    // Human human1("Spongebob", "Cook", 10);

    // // human1.name = "Rick";
    // // human1.occupation = "Scientist";
    // // human1.age = 70;

    // std::cout << human1.name << '\n';
    // std::cout << human1.occupation << '\n';
    // std::cout << human1.age << '\n';

    // human1.eat();
    // human1.drink();
    // human1.sleep();

    // Constructors are special methods that're automatically called when an object is instantiated
    // They are useful for assigning values to attributes as arguments

    // Abstraction = hiding unnecessary data from outside a class
    // getter = function that makes a private attribute readable
    // setter = function that makes a private attribute writeable

    // Stove stove(100);
    
    // //stove.temperature = 1000000;

    // stove.setTemperature(1000000);

    // std::cout << "The tempeature setting is: " << stove.getTemperature() << '\n';

    // Inheritance = A class can receive attributes and methods from another class
    //               Children classes inherit from a parent class
    //               Helps to reuse similar code found within multiple classes

    Dog dog;

    std::cout << dog.alive << '\n';
    dog.eat();
    dog.bark();

    Cat cat;

    cat.meow();



    return 0;
}