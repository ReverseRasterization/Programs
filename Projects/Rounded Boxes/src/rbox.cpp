#include "rbox.h"
#include <iostream>
#include <cmath>

void draw_rect(sf::VertexArray& m_verticies, sf::Vector2i size, sf::Vector2f position, float round_factor, float round_resolution) {
    const float pi = 3.14159;

    float degreeStep = 90*round_resolution;
    float num_triangles = std::ceil(90/degreeStep);

    m_verticies.resize(18 + ((num_triangles*3) * 2));

    // Draw the triangles for the rectangle
    int shortest_dimension;

    if (size.y > size.x){
        shortest_dimension = size.x;
    }else {
        shortest_dimension = size.y;
    }

    int loss = shortest_dimension*round_factor;

    // Top Portion of the rectangle

    sf::Vertex squareVertex;
    squareVertex.color = sf::Color::White;

    squareVertex.position = {position.x + loss, position.y}; // top left
    squareVertex.color = sf::Color::Red;
    m_verticies[0] = squareVertex;

    squareVertex.position = {(position.x + size.x)-loss, position.y}; // top right
    squareVertex.color = sf::Color::Green;
    m_verticies[1] = squareVertex;

    squareVertex.position = {position.x + loss, position.y + loss}; // bottom left
    squareVertex.color = sf::Color::Blue;
    m_verticies[2] = squareVertex;

    squareVertex.position = {position.x + loss, position.y + loss}; // bottom left
    squareVertex.color = sf::Color::Yellow;
    m_verticies[3] = squareVertex;

    squareVertex.position = {(position.x + size.x)-loss, position.y + loss}; // bottom right
    squareVertex.color = sf::Color::White;
    m_verticies[4] = squareVertex;

    squareVertex.position = {(position.x + size.x)-loss, position.y}; // top right
    squareVertex.color = sf::Color::Magenta;
    m_verticies[5] = squareVertex;

    // Bottom Portion of the rectangle

    squareVertex.position = {position.x + loss, (position.y + size.y)-loss}; // top left
    squareVertex.color = sf::Color::Red;
    m_verticies[6] = squareVertex;

    squareVertex.position = {(position.x + size.x)-loss, (position.y + size.y)-loss}; // top right
    squareVertex.color = sf::Color::Green;
    m_verticies[7] = squareVertex;

    squareVertex.position = {position.x + loss, position.y + size.y}; // bottom left
    squareVertex.color = sf::Color::Blue;
    m_verticies[8] = squareVertex;

    squareVertex.position = {position.x + loss, position.y + size.y}; // bottom left
    squareVertex.color = sf::Color::Yellow;
    m_verticies[9] = squareVertex;

    squareVertex.position = {(position.x + size.x)-loss, position.y + size.y}; // bottom right
    squareVertex.color = sf::Color::White;
    m_verticies[10] = squareVertex;

    squareVertex.position = {(position.x + size.x)-loss, (position.y + size.y)-loss}; // top right
    squareVertex.color = sf::Color::Magenta;
    m_verticies[11] = squareVertex;


    // Body Portion of the rectangle

    squareVertex.position = {position.x, position.y + loss}; // Top Left
    squareVertex.color = sf::Color::Red;
    m_verticies[12] = squareVertex;

    squareVertex.position = {position.x + size.x, position.y + loss}; // Top right
    squareVertex.color = sf::Color::Green;
    m_verticies[13] = squareVertex;

    squareVertex.position = {position.x, (position.y + size.y)-loss}; // Bottom Left
    squareVertex.color = sf::Color::Blue;
    m_verticies[14] = squareVertex;

    squareVertex.position = {position.x, (position.y + size.y)-loss}; // Bottom Left
    squareVertex.color = sf::Color::Yellow;
    m_verticies[15] = squareVertex;

    squareVertex.position = {position.x + size.x, (position.y + size.y)-loss}; // Bottom Right
    squareVertex.color = sf::Color::White;
    m_verticies[16] = squareVertex;

    squareVertex.position = {position.x + size.x, position.y + loss}; // Top right
    squareVertex.color = sf::Color::Magenta;
    m_verticies[17] = squareVertex;

    sf::Vertex nVertex;
    nVertex.color = sf::Color::Red; // Set the color of all vertices

    // Top right corner

    sf::Vector2f lastPeak = {(position.x + size.x), position.y + loss};

    std::cout << num_triangles << ", " << round_resolution << '\n';

    for (int i=0;i<num_triangles; i++) {
        int j = 18 + (i*3);

        nVertex.position = {(position.x + size.x)-loss, position.y + loss}; // origin
        nVertex.color = sf::Color::Red;
        m_verticies[j] = nVertex;

        nVertex.position = lastPeak; // this is the "bottom-right" of the triangle
        nVertex.color = sf::Color::Blue;
        m_verticies[j + 1] = nVertex;

        float currRad = (degreeStep*(i+1)) * pi/180;
        if (currRad > (90*(pi/180))) {
            currRad=90*(pi/180);
        }
        sf::Vector2f peak = {((position.x + size.x)-loss) + (static_cast<float>(std::cos(currRad))*loss), position.y - (static_cast<float>(std::sin(currRad)) * loss) + loss};

        nVertex.position = peak;  // this serves as the "peak", the outer vertex of the quarter-circle
        nVertex.color = sf::Color::Yellow;
        m_verticies[j+2] = nVertex;

        lastPeak = peak;

        std::cout << "(tr) Finished using index: " << j+2 << '\n';
    }

    //Bottom Right Corner
    lastPeak = {(position.x + size.x), (position.y + size.y)-loss};

    for (int i=0;i<num_triangles; i++) {
        int j = (18 + (num_triangles * 3) + (i*3));

        std::cout << "(br) starting @ " << j << '\n';

        nVertex.position = {(position.x + size.x)-loss, (position.y + size.y)-loss}; // origin
        nVertex.color = sf::Color::Red;
        m_verticies[j] = nVertex;

        nVertex.position = lastPeak; // this is the "bottom-right" of the triangle
        nVertex.color = sf::Color::Blue;
        m_verticies[j + 1] = nVertex;

        float currRad = (degreeStep*(i+1)) * pi/180;
        if (currRad > (90*(pi/180))) {
            currRad=90*(pi/180);
        }
        sf::Vector2f peak = {((position.x + size.x)-loss) + (static_cast<float>(std::cos(currRad))*loss), (position.y + size.y) + (static_cast<float>(std::sin(currRad)) * loss) - loss};

        nVertex.position = peak;  // this serves as the "peak", the outer vertex of the quarter-circle
        nVertex.color = sf::Color::Yellow;
        m_verticies[j+2] = nVertex;

        lastPeak = peak;
    }

    // TODO: Top & Bottom Left Corner
}

void RoundedSquare::changeResolution(float new_resolution) {
    round_resolution = new_resolution;
    draw_rect(m_verticies, size, position, round_factor, new_resolution);
}

RoundedSquare::RoundedSquare(sf::Vector2i size, sf::Vector2f position, float round_factor, float round_resolution): size(size), position(position), round_factor(round_factor), round_resolution(round_resolution) {
    m_verticies.setPrimitiveType(sf::PrimitiveType::Triangles);
    draw_rect(m_verticies, size, position, round_factor, round_resolution);
    
}