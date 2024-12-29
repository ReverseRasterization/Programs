#include <iostream>
#include <cmath>

class Shape {
    public:
        // Shape(double length){
        //     height = length;
        //     width = length;
        // }

        // Shape(double h, double w){
        //     height = h;
        //     width = w;
        // }
        virtual double Area() = 0; // virtual allows derived classes to override this method with their own implementation.
            
};

class Circle: public Shape {
    protected: // Accessed directely within the class, by derived classes, but not by outside code
        double width;

    public:
        //Circle(double w) : Shape(w){} 
        
        Circle (double w){
            width = w;
        }

        double Area() override { // Override forces the compiler to check that the base class's virtual function is the same as the subclass
            return 3.14 * std::pow((width/2),2);
        }
};

class Rectangle: public Shape {
    protected:
        double height, width;

    public:
        Rectangle(double h, double w){
            height = h;
            width = w;
        }

        double Area() override /*final*/ { // Final basically says this cannot be overwritten
            return height * width;
        }
};

class Square: public Rectangle {
    public:
        Square(double h, double w) : Rectangle(h,w){}; // This just constructs the square class using the single-parameter constructor from the rectangle class, in which it is derived from
};

void ShowArea(Shape& shape){
    std::cout << "Area: " << shape.Area() << '\n';
}

int main(){
    
    Rectangle rectangle(10,5);
    Circle circle(10);
    ShowArea(rectangle);
    ShowArea(circle);

    return 0;
}