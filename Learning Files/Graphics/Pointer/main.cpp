#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <chrono>


struct Bullet{
    sf::Vector2f direction;
    float speed = 2000;

    sf::CircleShape bullet = sf::CircleShape(5.0f);
};

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

    std::vector<Bullet> bullets;

    sf::Clock clock;

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("gunshot.wav"))
        return -1;

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
            if(event->is<sf::Event::MouseButtonPressed>()){
                Bullet nBullet;
                nBullet.direction = sf::Vector2f(laser[1].position.x - laser[0].position.x, laser[1].position.y - laser[0].position.y);
                nBullet.bullet.setPosition(laser[0].position);

                float magnitude = std::sqrt(nBullet.direction.x * nBullet.direction.x + nBullet.direction.y * nBullet.direction.y);
                if (magnitude != 0){
                    nBullet.direction.x /= magnitude;
                    nBullet.direction.y /= magnitude;
                }

                bullets.push_back(nBullet);

                sf::Sound(buffer).play();
                
            }
        }

        sf::Time dTime = clock.restart();
        float dt = dTime.asSeconds();

        window.clear();
        window.draw(laser);
        window.draw(triangle);


        for (auto it = bullets.begin(); it != bullets.end();){
            
            float newX = it->bullet.getPosition().x + (it->direction.x * it->speed * dt);
            float newY = it->bullet.getPosition().y + (it->direction.y * it->speed * dt);

            it->bullet.setPosition(sf::Vector2f(newX, newY));

            if (newX < 0 || newX > window.getSize().x || newY < 0 || newY > window.getSize().y){
                it = bullets.erase(it);
            }else {
                window.draw(it->bullet);
                ++it;
            }

            
        };

        window.display();
    }


    return 0;
}