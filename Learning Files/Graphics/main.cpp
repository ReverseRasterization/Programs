#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    const float r = 5;

    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");

    sf::CircleShape circle;
    circle.setRadius(r);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(1);
    circle.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {window.close();}
            if (event->is<sf::Event::MouseMoved>()){
                sf::Vector2f MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                MousePosition.x -= r;
                MousePosition.y -= r;

                std::cout << "X: " << MousePosition.x << "\nY: " << MousePosition.y << "\n\n"; 
                
                circle.setPosition(MousePosition);
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}