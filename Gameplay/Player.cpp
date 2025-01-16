#include "Player.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

#include "../Math/Force.h"

Player::Player()
{
    sprite_.set_sprite_path("Assets/Player.png");
    position_ = Vector2::half;
    position_.y = start_height_;
    hitable_.set_radius(7);
}

Player::~Player() = default;

Vector2 Player::get_position() const
{
    return Entity::get_position();
}

Vector2 Player::get_center_position() const
{
    return Entity::get_center_position();
}

void Player::draw_self(sf::RenderWindow& w)
{
    sprite_.draw_self(w);
    hitable_.draw(w);
}

void Player::handel_collision(const Collider& other)
{
    if (hitable_.get_collider().is_colliding(other))
    {
        std::cout << "collision \n";
    }
}

void Player::update(const Force force)
{
    Vector2 input = Vector2::zero;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        input.x = -0.1f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        input.x = 0.1f;

    std::cout << "Input: " << input << "\n";
    
    const Vector2 acceleration = input * speed_;  
    // std::cout << "Acceleration: " << acceleration << "\n";
    
    Vector2 new_velocity = force.add_force(position_, veclocity_, acceleration);
    new_velocity.y = 0; 

    std::cout << "Force-Adjusted Velocity: " << new_velocity << "\n";
    
    const float max_velocity = 50.0f;
    std::cout << "magnitude: " << new_velocity.magnitude() << "\n"; // magnitude keeps on growing and growing when input

    if (new_velocity.magnitude() > max_velocity)
        new_velocity = new_velocity.normalize() * input.x * max_velocity;

    if (input == Vector2::zero)
        new_velocity = Vector2::zero;

    // std::cout << "Velocity after Friction: " << new_velocity << "\n";
    
    veclocity_ = new_velocity;
    position_ += veclocity_;

    // std::cout << "Updated Position: " << position_ << "\n";

    sprite_.set_position(position_);
    hitable_.set_position(position_);
}

void Player::set_position(Vector2& target_pos)
{
    Entity::set_position(target_pos);
}
