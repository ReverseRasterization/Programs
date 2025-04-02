#pragma once

#include <SFML/Graphics.hpp>

class RoundedSquare : public sf::Drawable, public sf::Transformable {
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
            states.transform *= getTransform();

            target.draw(m_verticies, states);
        }

        sf::VertexArray m_verticies;

        sf::Vector2i size;
        sf::Vector2f position;

        float round_factor;
        float round_resolution;
    public:
        RoundedSquare(sf::Vector2i size, sf::Vector2f position, float round_factor, float round_resolution);

        void changeResolution(float new_resolution);
        void changeRoundingFactor(float new_factor);
};