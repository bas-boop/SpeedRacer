#include "Hittable.h"

Hittable::Hittable()
{
    position_ = Vector2(400,100);
    collider_.set_position(position_);
    circle_.setFillColor(sf::Color(255,0,0));
    circle_.setRadius(7);
    circle_.setPosition(position_.x, position_.y);

    Entity::Entity();
}

Hittable::~Hittable()
{
    Entity::~Entity();
}

void Hittable::draw(sf::RenderWindow& window)
{
    circle_.setPosition(position_.x, position_.y);

    if (should_show_)
        window.draw(circle_);
}

void Hittable::set_position(const Vector2& target_pos)
{
    collider_.set_position(target_pos);
    Entity::set_position(target_pos);
}

void Hittable::set_radius(const float target)
{
    collider_.set_radius(target);
}

Collider Hittable::get_collider()
{
    return collider_;
}