#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <array>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1000,1000}), "Mouse Pointer");

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, {0, -50}); // This is the tip
    triangle.setPoint(1, {50, 50});
    triangle.setPoint(2, {-50, 50});
    triangle.setFillColor(sf::Color::Green);
    triangle.setOrigin({0,0});
    triangle.setPosition({500, 500});

    sf::VertexArray laser(sf::PrimitiveType::Lines, 2);
    laser[0].position = sf::Vector2f(500,500);
    

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (event->is<sf::Event::MouseMoved>()){
                sf::Vector2f MousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                sf::Vector2f TrianglePos = triangle.getPosition();
                double dX = (double)MousePos.x - TrianglePos.x;
                double dY = (double)MousePos.y - TrianglePos.y;

                triangle.setRotation(sf::degrees((atan2(dY, dX)) * (180.0f / 3.14159265359f)+90));

                laser[1].position = sf::Vector2f(MousePos.x, MousePos.y);
            }
        }

        window.clear();
        window.draw(triangle);
        window.draw(laser);
        window.display();
    }


    return 0;
}