#include "Force.h"
#include "../Gameplay/Game.h"

Vector2 Force::add_force(const Vector2& inital_position, const Vector2 initial_velocity, const Vector2 acceratation) const
{
    const float time = clock.getElapsedTime().asSeconds();
    return inital_position + (initial_velocity * time) + (Vector2::half * acceratation * (time * time));
}