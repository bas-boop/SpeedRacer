#include "Collider.h"

Collider::Collider() = default;

Collider::Collider(const float radius_target)
{
    radius_ = radius_target;
}

bool Collider::is_colliding(const Collider& other) const
{
    if (other.position_ == position_)
        return true;
    
    if (other.position_.magnitude() - position_.magnitude() <= other.radius_ + radius_)
        return true;
    
    return false;
}

void Collider::set_position(Vector2& vector2)
{
    Entity::set_position(vector2);
}

void Collider::set_position(const Vector2& vector2)
{
    Entity::set_position(vector2);
}
