#include <iostream>
#include <SFML/Graphics.hpp>
#include "rbox.h"
#include "slider.h"

/* TODO:
    1. Add a width & height slider
    2. Allow sliders to be rounded
*/

int main()
{
    float currRes = .25f;

    sf::RenderWindow window(sf::VideoMode({500, 800}), "Rounded Box Demo");
    RoundedSquare rsquare = RoundedSquare({300, 100}, {100.f, 200.f}, .5f, currRes);

    // Slider parameters
    std::vector<sf::Vector2f> lineEnds = {{100.f, 400.f}, {400.f, 400.f}};
    Slider::sliderPointType pointType = Slider::sliderPointType::Box;
    int barThickness = 10;
    sf::Vector2f sliderPointProportions = {0.05f, 2.5f};
    sf::Vector2f lineBoundarySize = {0.f, 0.f};
    double initialValue = currRes;
    double valueStep = .05;
    double minValue = 0.05;
    double maxValue = 1;

    // Creating the Slider instance
    Slider resSlider(lineEnds, pointType, barThickness, sliderPointProportions, lineBoundarySize, 
                        initialValue, valueStep, minValue, maxValue, sf::Color::White);
    
    Slider factorSlider({{100.f, 500.f}, {400.f, 500.f}}, pointType, barThickness, sliderPointProportions, lineBoundarySize, 
                        .5, valueStep, 0, 0.5, sf::Color::White);



    sf::Clock clock;

    bool mouseActive = false;
    int subscribed; // 1 for the resolution slider, 2 for the factor slider

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
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (subscribed == 1){
                        resSlider.update(mousePos);
                        rsquare.changeResolution(resSlider.getValue());
                    }else if (subscribed == 2) {
                        factorSlider.update(mousePos);
                        rsquare.changeRoundingFactor(factorSlider.getValue());
                    }   
                }
            }
            if(event->is<sf::Event::MouseButtonPressed>()) {
                mouseActive = true;
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if(resSlider.inBounds(mousePos)){
                    resSlider.toggleSubscription(true);
                    subscribed = 1;
                } else if(factorSlider.inBounds(mousePos)){
                    factorSlider.toggleSubscription(true);
                    subscribed = 2;
                }
            }
            if(event->is<sf::Event::MouseButtonReleased>()) {
                mouseActive = false;
                resSlider.toggleSubscription(false);
                factorSlider.toggleSubscription(false);
            }
        }

        // Calculate the FPS
        float deltaTime = clock.restart().asSeconds();
        int fps = static_cast<int>(1.f / deltaTime);

        // Update the FPS text
        //std::cout << "FPS: " << std::to_string(fps) << '\n';

        window.clear();
        window.draw(rsquare);
        window.draw(resSlider);
        window.draw(factorSlider);
        window.display();
    }
    

    return 0;
}