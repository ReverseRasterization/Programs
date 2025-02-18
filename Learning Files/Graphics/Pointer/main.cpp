#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <chrono>

// TOOD: Add a score for when enemies die
// TODO: Add accuracy counter
// TODO: Add indicators of critial hit (factor of 1.4 - 2), good hit (factor of .76 - 1.3), or weak hit (factor of .3-.75)
// TODO: Add enemy movement
// TODO: Allow enemies to attack you
// TODO: Add multiple enemies (implement max enemies & enemies per second)
// TODO: Add an FPS counter
// TODO: Add a settings UI that adjusts volume, max enemies, enemies per second, and toggles the FPS counter

struct Bullet{
    sf::Vector2f direction;

    float speed = 2000;
    int base_damage = 15;

    sf::CircleShape bullet = sf::CircleShape(5.0f);
};

struct Enemy{
    float health = 100;
    int speed = 10;

    // Some hitbox data, the rectangles getPosition function is at the top left corner of the rectangle
    int y_top;
    int y_bottom;
    int x_left;
    int x_right;

    sf::RectangleShape entity = sf::RectangleShape({96.f, 80.f});
    sf::RectangleShape healthBarBG = sf::RectangleShape({96.f, 10});
    sf::RectangleShape healthBarFG = sf::RectangleShape({96.f, 10});
};

float getDistance(int x1, int x2, int y1, int y2);
Enemy summonEnemy(sf::Texture& enemy_texture);
Bullet fireBullet(sf::Vector2f mousePos, sf::Vector2f trianglePos);

int main()
{
    srand(time(NULL));

    // Make window

    sf::RenderWindow window(sf::VideoMode({1000,1000}), "Mouse Pointer", sf::Style::Close);
    window.setMouseCursorVisible(false);

    // Make Triangle

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, {0, -25}); // This is the tip
    triangle.setPoint(1, {25, 25});
    triangle.setPoint(2, {-25, 25});
    triangle.setFillColor(sf::Color::Green);
    triangle.setOrigin({0,0});
    triangle.setPosition({500, 500});

    // Load & apply textures

    sf::Texture xhairTexture;
    sf::Texture enemy_texture;
    if(!xhairTexture.loadFromFile("Textures/xhair.png") || !enemy_texture.loadFromFile("Textures/enemy.png")){
        return -1;
    }

    sf::RectangleShape xhair({75.f, 75.f});
    xhair.setTexture(&xhairTexture);

    // Make enemy

    Enemy enemy = summonEnemy(enemy_texture);

    std::vector<Bullet> bullets;
    sf::Clock clock;

    // Load sounds

    sf::SoundBuffer gunshot_buffer;
    sf::SoundBuffer hit_buffer;
    sf::SoundBuffer enemy_death_buffer;
    if (!gunshot_buffer.loadFromFile("Sounds/gunshot.wav") || !hit_buffer.loadFromFile("Sounds/hit.wav") || !enemy_death_buffer.loadFromFile("Sounds/enemydied.wav"))
        return -1;

    sf::Sound gunshot (gunshot_buffer);
    sf::Sound hitSound(hit_buffer);
    sf::Sound eDeathSound(enemy_death_buffer);

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
                bullets.push_back(fireBullet(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)), triangle.getPosition()));
                gunshot.play();
            }
            if(event->is<sf::Event::KeyPressed>()){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
                    enemy = summonEnemy(enemy_texture);
                }
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
                float damage = it->base_damage;
                float damage_modifier = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2.0f;

                if (damage_modifier < .3){
                    damage_modifier = .3;
                }

                damage*=damage_modifier;

                enemy.health -= damage;

                if (enemy.health <= 0) {
                    enemy.health = 0;
                    eDeathSound.play();

                    enemy = summonEnemy(enemy_texture);
                }else {
                    hitSound.play();
                }

                enemy.healthBarFG.setSize(sf::Vector2f(enemy.healthBarBG.getSize().x * (static_cast<float>(enemy.health)/100), enemy.healthBarFG.getSize().y));

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

Bullet fireBullet(sf::Vector2f mousePos, sf::Vector2f trianglePos) {
    Bullet nBullet;
    nBullet.direction = sf::Vector2f(mousePos.x - trianglePos.x, mousePos.y - trianglePos.y);
    nBullet.bullet.setPosition(sf::Vector2f(trianglePos.x-5, trianglePos.y-5));

    float magnitude = std::sqrt(nBullet.direction.x * nBullet.direction.x + nBullet.direction.y * nBullet.direction.y);
    if (magnitude != 0){
        nBullet.direction.x /= magnitude;
        nBullet.direction.y /= magnitude;
    }

    return nBullet;
}

float getDistance(int x1, int x2, int y1, int y2){ // utilizes c^2 = a^2 + b^2 to determine distance
    // a = x diff
    // b = y diff

    int a = std::abs(x2-x1);
    int b = std::abs(y2-y1);

    return sqrt((a*a)+(b*b));
}

Enemy summonEnemy(sf::Texture& enemy_texture){
    Enemy nEnemy;

    sf::Vector2f position(500, 500);

    while (getDistance(500, position.x, 500, position.y) < 200)
    {
        position = sf::Vector2f(rand()%800, 100 + rand()%700);
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