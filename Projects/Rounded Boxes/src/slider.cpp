#include "slider.h"
#include <cmath>
#include <iostream>

void drawRect(sf::Vector2f position, sf::Vector2f size, sf::VertexArray& m_verticies, int startingIndex) {
    sf::Vertex nBoundVert;

    nBoundVert.color = sf::Color::Red;
    nBoundVert.position = position; // top left corner
    m_verticies[startingIndex] = nBoundVert;

    nBoundVert.color = sf::Color::Green;
    nBoundVert.position = {position.x + size.x, position.y}; // top right corner
    m_verticies[startingIndex + 1] = nBoundVert;

    nBoundVert.color = sf::Color::Blue;
    nBoundVert.position = {position.x + size.x, position.y + size.y}; // bottom right corner
    m_verticies[startingIndex + 2] = nBoundVert;

    nBoundVert.color = sf::Color::Yellow;
    nBoundVert.position = {position.x + size.x, position.y + size.y}; // bottom right corner
    m_verticies[startingIndex + 3] = nBoundVert;

    nBoundVert.color = sf::Color::White;
    nBoundVert.position = {position.x, position.y + size.y}; // bottom left corner
    m_verticies[startingIndex + 4] = nBoundVert;

    nBoundVert.color = sf::Color::Cyan;
    nBoundVert.position = position; // top left corner
    m_verticies[startingIndex + 5] = nBoundVert;
}

void Slider::drawNewPointPosition() {
    float size = sqrt(
        pow((lineEnds[1].x - lineEnds[0].x), 2) +
        pow((lineEnds[1].y - lineEnds[0].y), 2)
    );

    // Step 1: Calculate distance between max x and min x (delta x)
    // Step 2: Calculate difference between max and min (delta v)
    // Step 3: Calculate difference between the current value and the minimum value (delta v2)
    // step 4: Do delta v2 divided by delta v (diff)
    // Step 5: Do delta x * diff (z)
    // Step 6: do min x + z and then you have your new x

    sf::Vector2f squareSize = {
        size * sliderPointProportions.x,
        barThickness * sliderPointProportions.y
    };

    sf::Vector2f pos = {(lineEnds[0].x + ((lineEnds[1].x - lineEnds[0].x) * static_cast<float>(((currentValue - min)/(max - min))))) - (squareSize.x/2), 
                         lineEnds[0].y - (squareSize.y/2)};
    
    drawRect(pos, squareSize, m_verticies, m_verticies.getVertexCount()-6);
}

void Slider::toggleSubscription(bool toggle){
    subscribed = toggle;
}

bool Slider::inBounds(sf::Vector2i mouse_pos) {
    // We need to get the verticies for the top left (last vertici) & bottom left corners (2nd to last vertici)
    return (mouse_pos.y >= m_verticies[m_verticies.getVertexCount()-1].position.y && mouse_pos.y <= m_verticies[m_verticies.getVertexCount()-2].position.y) && 
           (mouse_pos.x >= lineEnds[0].x && mouse_pos.x <= lineEnds[1].x);
}

void Slider::update(sf::Vector2i mouse_pos) {
    if (!subscribed) {return;}

    if (mouse_pos.x >= lineEnds[0].x && mouse_pos.x <= lineEnds[1].x) {
        double nValue = min + (max - min) * (mouse_pos.x - lineEnds[0].x)/(lineEnds[1].x - lineEnds[0].x);
        std::cout << nValue << '\n';

        currentValue = min + round((nValue - min) / step) * step;

        std::cout << currentValue << '\n';

        drawNewPointPosition();
    }
}

double Slider::getValue() {
    return currentValue;
}

Slider::Slider(std::vector<sf::Vector2f> line_ends, sliderPointType slider_point_type, int bar_thickness, sf::Vector2f slider_point_proportions, sf::Vector2f line_boundary_size, double initial_value, double value_step, double min, double max):
        lineEnds(line_ends), pointType(slider_point_type), barThickness(bar_thickness), sliderPointProportions(slider_point_proportions), lineBoundSize(line_boundary_size), currentValue(initial_value), step(value_step), min(min), max(max) 
{
    // Get & Set the verticy size
    int vert_size = 12; // 12 verticies for the line & point
    int nextAvailableVertIndex = 0;
    if (line_boundary_size.x > 0.f) { // The user wants the line boundaries drawn
        vert_size += 12;
    }

    m_verticies.resize(vert_size);
    m_verticies.setPrimitiveType(sf::PrimitiveType::Triangles);

    // Draw the boundaries (if applicable)
    // the top-left-corner of the left boundary will be (first line end.x - bound_size.x, first line end.y - (bound_size.y/2))
    if (line_boundary_size.x > 0.f) {
        nextAvailableVertIndex = 12;

        drawRect({line_ends[0].x - lineBoundSize.x, line_ends[0].y-(lineBoundSize.y/2)}, lineBoundSize, m_verticies, 0); // Left Bound
        drawRect({line_ends[1].x, line_ends[0].y-(lineBoundSize.y/2)}, lineBoundSize, m_verticies, 6); // Right Bound
    }

    // Draw the actual line itself
    drawRect({line_ends[0].x, line_ends[1].y-(bar_thickness/2)}, {line_ends[1].x-line_ends[0].x, static_cast<float>(bar_thickness)}, m_verticies, nextAvailableVertIndex);
    nextAvailableVertIndex+=6;

    // Draw the point
    drawNewPointPosition();
}