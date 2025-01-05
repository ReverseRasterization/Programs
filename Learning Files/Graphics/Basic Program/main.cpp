#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

int main()
{
    float r = 5;
    sf::Vector2f MousePosition;

    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");

    sf::CircleShape circle;
    circle.setRadius(r);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(1);
    circle.setFillColor(sf::Color::Red);

    sf::Clock clock;
    int frameCt = 0;
    float deltaTime = 0.0f;

    clock.start();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {window.close();}
            if (event->is<sf::Event::MouseMoved>()){
                MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                MousePosition.x -= r;
                MousePosition.y -= r;
                
                circle.setPosition(MousePosition);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            r+=.5;

            MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            MousePosition.x -= r;
            MousePosition.y -= r;

            circle.setRadius(r);
            circle.setPosition(MousePosition);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            r-=.5;

            if (r < 5) {
                r = 5;
            }

            MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            MousePosition.x -= r;
            MousePosition.y -= r;

            circle.setRadius(r);
            circle.setPosition(MousePosition);
        }

        
        frameCt++;

        if(clock.getElapsedTime().asSeconds() >= 1.0f) 
        {
            std::cout << "FPS: " << frameCt << '\n';
            clock.restart();
            frameCt = 0;
        }


        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}