#include "Entity.h"

Entity::Entity() = default;

Entity::~Entity() = default;

Vector2 Entity::get_position() const
{
    return position_;
}

Vector2 Entity::get_center_position() const
{
    return Vector2::zero;
}

void Entity::set_position(const Vector2& target_pos)
{
    position_ = target_pos;
}