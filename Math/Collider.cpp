#include "Collider.h"

Collider::Collider()
{
    Entity::Entity();
}

Collider::Collider(const float radius_target)
{
    radius_ = radius_target;
}

Collider::~Collider()
{
    Entity::~Entity();
}

bool Collider::is_colliding(const Collider& other) const
{
    if (other.position_ == position_)
        return true;

    return (position_ - other.position_).magnitude() <= radius_ + other.radius_;
}

void Collider::set_position(const Vector2& vector2)
{
    Entity::set_position(vector2);
}

void Collider::set_radius(const float target)
{
    radius_ = target;
}
