#pragma once
#include <SFML/System/Clock.hpp>

#include "Vector2.h"

class Force
{
public:
    Vector2 add_force(const Vector2& inital_position, const Vector2 initial_velocity, const Vector2 acceratation) const;
    
    sf::Clock clock;
};
