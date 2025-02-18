#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <chrono>

// TODO: Fix when enenmies health bars go off screen because they spawn too high
// TODO: Add SFX for when enemies die
// TOOD: Add a score for when enemies die
// TODO: Add accuracy counter
// TODO: Add an FPS counter
// TODO: Add enemy movement


struct Bullet{
    sf::Vector2f direction;

    float speed = 2000;
    int base_damage = 15;
    int critial_multiplier = 2;

    sf::CircleShape bullet = sf::CircleShape(5.0f);
};

struct Enemy{
    int health = 100;
    int speed = 10;

    // Some hitbox data, the rectangles getPosition function is at the top left corner of the rectangle
    int y_top;
    int y_bottom;
    int x_left;
    int x_right;

    sf::RectangleShape entity = sf::RectangleShape({128.f, 107.f});
    sf::RectangleShape healthBarBG = sf::RectangleShape({128.f, 20});
    sf::RectangleShape healthBarFG = sf::RectangleShape({128.f, 20});
};

Enemy summonEnemy(sf::Texture& enemy_texture){
    Enemy nEnemy;

    sf::Vector2f position(500, 500);

    while ((std::abs(position.x - 500) < 100 && std::abs(position.y - 500) < 100))
    {
        position = sf::Vector2f(rand()%800, rand()%800);

    }

    nEnemy.entity.setPosition(position);
    nEnemy.healthBarBG.setPosition(sf::Vector2f(position.x, position.y-30));
    nEnemy.healthBarFG.setPosition(nEnemy.healthBarBG.getPosition());

    nEnemy.healthBarFG.setFillColor(sf::Color(0,255,0));

    nEnemy.y_top = position.y;
    nEnemy.y_bottom = position.y+107;

    nEnemy.x_left = position.x;
    nEnemy.x_right = position.x + 128;

    nEnemy.entity.setTexture(&enemy_texture);

    return nEnemy;
}

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode({1000,1000}), "Mouse Pointer", sf::Style::Close);
    window.setMouseCursorVisible(false);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, {0, -25}); // This is the tip
    triangle.setPoint(1, {25, 25});
    triangle.setPoint(2, {-25, 25});
    triangle.setFillColor(sf::Color::Green);
    triangle.setOrigin({0,0});
    triangle.setPosition({500, 500});

    sf::Texture xhairTexture;
    if(!xhairTexture.loadFromFile("xhair.png")){
        return -1;
    }
    sf::Texture enemy_texture;
    if(!enemy_texture.loadFromFile("enemy.png")){
        return -1;
    }


    sf::RectangleShape xhair({75.f, 75.f});
    xhair.setTexture(&xhairTexture);

    Enemy enemy = summonEnemy(enemy_texture);

    std::vector<Bullet> bullets;

    sf::Clock clock;

    sf::SoundBuffer gunshot_buffer;
    if (!gunshot_buffer.loadFromFile("gunshot.wav"))
        return -1;

    sf::Sound gunshot (gunshot_buffer);

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
                xhair.setPosition(MousePos-sf::Vector2f(37.5, 37.5));
            }
            if(event->is<sf::Event::MouseButtonPressed>()){
                sf::Vector2f MousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                sf::Vector2f TrianglePos = triangle.getPosition();

                Bullet nBullet;
                nBullet.direction = sf::Vector2f(MousePos.x - TrianglePos.x, MousePos.y - TrianglePos.y);
                nBullet.bullet.setPosition(sf::Vector2f(triangle.getPosition().x-5, triangle.getPosition().y-5));

                float magnitude = std::sqrt(nBullet.direction.x * nBullet.direction.x + nBullet.direction.y * nBullet.direction.y);
                if (magnitude != 0){
                    nBullet.direction.x /= magnitude;
                    nBullet.direction.y /= magnitude;
                }

                bullets.push_back(nBullet);

                gunshot.play();
                
            }
        }

        sf::Time dTime = clock.restart();
        float dt = dTime.asSeconds();

        window.clear();

        for (auto it = bullets.begin(); it != bullets.end();){
            
            float newX = it->bullet.getPosition().x + (it->direction.x * it->speed * dt);
            float newY = it->bullet.getPosition().y + (it->direction.y * it->speed * dt);

            it->bullet.setPosition(sf::Vector2f(newX, newY));

            if (newX > enemy.x_left && newX < enemy.x_right && newY > enemy.y_top && newY < enemy.y_bottom){
                enemy.health -= it->base_damage;

                if (enemy.health <= 0) {
                    enemy.health = 0;

                    enemy = summonEnemy(enemy_texture);
                }

                enemy.healthBarFG.setSize(sf::Vector2f(enemy.healthBarBG.getSize().x * (static_cast<float>(enemy.health)/100), 20));

                it = bullets.erase(it);
                break;
            }

            if (newX < 0 || newX > window.getSize().x || newY < 0 || newY > window.getSize().y){
                it = bullets.erase(it);
                break;
            }else {
                window.draw(it->bullet);
                ++it;
            }

            
        };

        window.draw(enemy.entity);
        window.draw(enemy.healthBarBG);
        window.draw(enemy.healthBarFG);
        window.draw(triangle);
        window.draw(xhair);
        window.display();
    }


    return 0;
}