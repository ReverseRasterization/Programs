#pragma once
#include <variant>
#include <SFML/Graphics.hpp>

class Slider {
    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
            states.transform *= getTransform();

            target.draw(m_verticies, states);
        }

        sf::VertexArray m_verticies;
        std::variant<int, float, double> currentValue;
        std::variant<int, float, double> valueStep;
        std::variant<int, float, double> min;
        std::variant<int, float, double> max;

        std::variant<int, float, double>& targetVariable;

        sf::Vector2i position;
        sf::Vector2i size;
        float barSize;


    public:
        Slider(sf::Vector2i position, sf::Vector2i size, float bar_size, std::variant<int, float, double> initial_value,
                                                                         std::variant<int, float, double> value_step,
                                                                         std::variant<int, float, double> min,
                                                                         std::variant<int, float, double> max, std::variant<int, float, double>& target_variable);

        void update(sf::Vector2i mouse_position);
}