#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Slider : public sf::Drawable, public sf::Transformable {
    
    public:
        enum sliderPointType{Box};

        Slider(std::vector<sf::Vector2f> line_ends, sliderPointType slider_point_type, int bar_thickness, sf::Vector2f slider_point_proportions, sf::Vector2f line_boundary_size,  
                                                                         double initial_value,
                                                                         double value_step,
                                                                         double min,
                                                                         double max, sf::Color color);

        
        void update(sf::Vector2i mouse_pos);
        double getValue();

        void toggleSubscription(bool toggle);
        bool inBounds(sf::Vector2i mouse_pos);
    
    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
            states.transform *= getTransform();

            target.draw(m_verticies, states);
        }
        void drawNewPointPosition();

        sf::VertexArray m_verticies; // The main verticies, the last 6 indicies are for the point

        double currentValue;
        double step;
        double min;
        double max;

        bool subscribed = false; // indicates if the slider is "subscribed" to the mouse

        std::vector<sf::Vector2f> lineEnds;
        sf::Vector2f lineBoundSize; // Thickness, Height
        sliderPointType pointType;

        sf::Vector2f sliderPointProportions; // relative to the size of the bar
        int barThickness;
        sf::Color color;
};