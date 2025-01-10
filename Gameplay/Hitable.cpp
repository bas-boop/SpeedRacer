﻿#include "Hitable.h"

Hitable::Hitable()
{
    position_ = Vector2(400,100);
    collider_.set_position(position_);
    circle_.setFillColor(sf::Color(255,0,0));
    circle_.setRadius(7);
    circle_.setPosition(position_.x, position_.y);
}

Collider Hitable::get_collider()
{
    return collider_;
}

void Hitable::draw(sf::RenderWindow& window)
{
    circle_.setPosition(position_.x, position_.y);
    window.draw(circle_);
}

void Hitable::set_position(Vector2& target_pos)
{
    collider_.set_position(target_pos);
    Entity::set_position(target_pos);
}

void Hitable::set_position(const Vector2& target_pos)
{
    Entity::set_position(target_pos);
}

void Hitable::set_radius(const float target)
{
    collider_.set_radius(target);
}

