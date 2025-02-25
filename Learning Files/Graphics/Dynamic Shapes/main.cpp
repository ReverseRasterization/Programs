#include <iostream>
#include <SFML/Graphics.hpp>

#define WINDOW_CONST = 500


int main()
{

    sf::Vector2f squareSize = sf::Vector2f(50.f, 50.f);
    sf::Vector2f squarePos = sf::Vector2f(225.f, 225.f);

    sf::RenderWindow window(sf::VideoMode({500, 500}), "Dynamic Shapes Test");
    sf::RectangleShape square;
    square.setSize(squareSize);
    square.setPosition(squarePos);

    while(window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>()){
                window.close();
            }

            if(event->is<sf::Event::Resized>()){
                int newWidth = window.getSize().x;
                int newHeight = window.getSize().y;

                std::cout << square.getSize().x;
            }
        }

        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}