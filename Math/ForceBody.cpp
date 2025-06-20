#include "ForceBody.h"
#include "../Gameplay/Game.h"

ForceBody::~ForceBody()
{
    Entity::~Entity();
}

void ForceBody::add_force(const Vector2& force)
{
    current_force += force;
}

void ForceBody::set_force(const Vector2& force)
{
    current_force = force;
    velocity_ = Vector2::zero;
}

void ForceBody::update_physics()
{
    const float time = clock.restart().asSeconds();
    
    add_force(velocity_.inverted() * friction_);

    velocity_ = velocity_ + acceleration() * time;
    position_ = position_ + velocity_ * current_speed_ * time;

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
