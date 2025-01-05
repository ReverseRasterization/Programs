#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <vector>
#include <chrono>

int main()
{
    std::vector<sf::CircleShape> circles{};
    std::vector<sf::Color> colors = {
        sf::Color::Black,
        sf::Color::White,
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan
    };
    int currColor = 2;

    sf::Vector2f MousePosition;

    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Circle Thingy");
    window.setFramerateLimit(140);

    sf::CircleShape circle;
    float r = 5;
    float growthFactor = 500;

    circle.setRadius(r);
    circle.setOutlineColor(colors[currColor]);
    circle.setOutlineThickness(1);
    circle.setFillColor(sf::Color::Red);

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    sf::Clock frameDisplayClock;
    sf::Clock deltaClock;
    float fps;

    sf::Font font;
    if (!font.openFromFile("Fonts\\Gameplay.ttf"))
    {
        std::cout << "Failed to load font!";
        return -1;
    }

    sf::Text fpsCounter(font);

    fpsCounter.setString("FPS: 0");
    fpsCounter.setCharacterSize(24);
    fpsCounter.setFillColor(sf::Color::White);
    fpsCounter.setStyle(sf::Text::Bold);
    fpsCounter.setPosition({10,10});

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
            if (event->is<sf::Event::KeyPressed>()){
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
                    circles.push_back(sf::CircleShape(circle));
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)){
                    circles.clear();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                    if (currColor == 0) {
                        currColor = 7;
                    }else {
                        currColor--;
                    }

                    circle.setFillColor(colors[currColor]);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                    if (currColor == 7) {
                        currColor = 0;
                    }else {
                        currColor++;
                    }

                    circle.setFillColor(colors[currColor]);
                }

            }
        }

        float dTime = deltaClock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            r+=(growthFactor*dTime);

            MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            MousePosition.x -= r;
            MousePosition.y -= r;

            circle.setRadius(r);
            circle.setPosition(MousePosition);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            r-=(growthFactor*dTime);

            if (r < 5) {
                r = 5;
            }

            MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            MousePosition.x -= r;
            MousePosition.y -= r;

            circle.setRadius(r);
            circle.setPosition(MousePosition);
        }

        

        if (frameDisplayClock.getElapsedTime().asSeconds() >= .5) {
            fps = (1e9f/static_cast<float>((std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count())));
            fpsCounter.setString("FPS: " + std::to_string(static_cast<int>(fps)));

            frameDisplayClock.restart();
        }
        
        
        start = std::chrono::high_resolution_clock::now();

        window.clear();
        for (const auto& c : circles) {
            window.draw(c);
        }
        window.draw(circle);
        window.draw(fpsCounter);
        window.display();

        end = std::chrono::high_resolution_clock::now();

        
    }

    return 0;
}