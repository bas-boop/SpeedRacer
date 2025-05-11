#include "ForceBody.h"

#include <iostream>

#include "../Gameplay/Game.h"

ForceBody::~ForceBody()
{
    Entity::~Entity();
}

Vector2 ForceBody::add_force(const Vector2& inital_position, const Vector2 initial_velocity, const Vector2 acceratation) const
{
    const float time = clock.getElapsedTime().asSeconds();
    return inital_position + (initial_velocity * time) + (Vector2::half * acceratation * (time * time));
}

void ForceBody::add_force(const Vector2& force)
{
    current_force = current_force + force;
}

void ForceBody::set_force(const Vector2& force)
{
    current_force = force;
    //velocity_ = Vector2::zero;
}

void ForceBody::update_physics()
{
    float time = clock.restart().asSeconds();
    
    add_force(velocity_.inverted() * friction_);

    velocity_ = velocity_ + acceleration() * time;
    position_ = position_ + velocity_ * speed_ * time;

    current_force = Vector2::zero;
}

Vector2 ForceBody::get_position() const
{
    return Entity::get_position();
}

Vector2 ForceBody::get_center_position() const
{
    return Entity::get_center_position();
}

void ForceBody::set_position(const Vector2& target_pos)
{
    Entity::set_position(target_pos);
}

Vector2 ForceBody::acceleration() const
{
    const float force = current_force.magnitude();
    const Vector2 normalized = current_force.normalize();
    return normalized * force / mass_;
}
