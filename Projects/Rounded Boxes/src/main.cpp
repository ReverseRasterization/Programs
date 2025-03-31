#include <iostream>
#include <SFML/Graphics.hpp>
#include "rbox.h"

int main()
{
    float currRes = .25f;

    sf::RenderWindow window(sf::VideoMode({500, 500}), "Rounded Box Demo");
    RoundedSquare rsquare = RoundedSquare({50, 200}, {100.f, 200.f},.5f, currRes);

    sf::Clock clock;

    while(window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
            if(event->is<sf::Event::KeyPressed>()) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                    currRes*=1.2;
                    
                }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                    currRes*=.98;
                }

                if (currRes > 1.f) {
                    currRes=1.f;
                }else if(currRes<0.f){
                    currRes=0.f;
                }

                //std::cout << currRes << '\n';
                rsquare.changeResolution(currRes);
            }
        }

        // Calculate the FPS
        float deltaTime = clock.restart().asSeconds();
        int fps = static_cast<int>(1.f / deltaTime);

        // Update the FPS text
        //std::cout << "FPS: " << std::to_string(fps) << '\n';

        window.clear();
        window.draw(rsquare);
        window.display();
    }
    

    return 0;
}