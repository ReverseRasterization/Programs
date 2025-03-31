#include "slider.h"

Slider::Slider(sf::Vector2i position, sf::Vector2i size, float bar_size, std::variant<int, float, double> initial_value, std::variant<int, float, double> value_step, std::variant<int, float, double> min, std::variant<int, float, double> max, std::variant<int, float, double>& target_variable): 
position(position), size(size), barSize(bar_size), currentValue(initial_value), valueStep(value_step), min(min), max(max), targetVariable(target_variable){
                                                                            
}