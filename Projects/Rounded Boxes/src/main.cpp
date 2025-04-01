#include <iostream>
#include <SFML/Graphics.hpp>
#include "rbox.h"
#include "slider.h"

int main()
{
    float currRes = .25f;

    sf::RenderWindow window(sf::VideoMode({500, 500}), "Rounded Box Demo");
    RoundedSquare rsquare = RoundedSquare({300, 100}, {100.f, 200.f}, .5f, currRes);

    // Slider parameters
    std::vector<sf::Vector2f> lineEnds = {{100.f, 400.f}, {400.f, 400.f}};  // Correct vector type
    Slider::sliderPointType pointType = Slider::sliderPointType::Box;
    int barThickness = 10;
    sf::Vector2f sliderPointProportions = {0.05f, 2.5f};
    sf::Vector2f lineBoundarySize = {10.f, 50.f};
    double initialValue = 9.0;
    double valueStep = 0.25;
    double minValue = 9.0;
    double maxValue = 10.0;

    // Creating the Slider instance
    Slider widthSlider(lineEnds, pointType, barThickness, sliderPointProportions, lineBoundarySize, 
                        initialValue, valueStep, minValue, maxValue);



    sf::Clock clock;

    bool mouseActive = false;

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
            if(event->is<sf::Event::MouseMoved>()) {
                if (mouseActive) {
                    widthSlider.update(sf::Mouse::getPosition(window));
                }
            }
            if(event->is<sf::Event::MouseButtonPressed>()) {
                mouseActive = true;
                if(widthSlider.inBounds(sf::Mouse::getPosition(window))) {widthSlider.toggleSubscription(true);}
            }
            if(event->is<sf::Event::MouseButtonReleased>()) {
                mouseActive = false;
                widthSlider.toggleSubscription(false);
            }
        }

        // Calculate the FPS
        float deltaTime = clock.restart().asSeconds();
        int fps = static_cast<int>(1.f / deltaTime);

        // Update the FPS text
        //std::cout << "FPS: " << std::to_string(fps) << '\n';

        window.clear();
        window.draw(rsquare);
        window.draw(widthSlider);
        window.display();
    }
    

    return 0;
}