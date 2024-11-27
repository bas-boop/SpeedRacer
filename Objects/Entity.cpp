#include "Entity.h"

Entity::~Entity() = default;

Vector2 Entity::get_position() const
{
    return position_;
}

Vector2 Entity::get_center_position()
{
    return Vector2::zero;
}
