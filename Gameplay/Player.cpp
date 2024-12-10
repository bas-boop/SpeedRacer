#include "Player.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

Player::Player()
{
    position_.y = start_height_;

    position_ = Vector2::half;
}

Player::~Player()
{
    
}

Vector2 Player::get_position() const
{
    return Entity::get_position();
}

Vector2 Player::get_center_position()
{
    return Entity::get_center_position();
}

void Player::update()
{
    int input = 0;
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        input = 1;
        std::cout << "left\n";
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        input = -1;
        std::cout << "right\n";
    }

    position_.x += input * speed_;

    std::cout << position_.x << "\n";
    
    // shape_.setRadius(shape_.getRadius() + delta_time());
    //
    // // Set the origin of the circle shape to its center
    // shape_.setOrigin(shape_.getRadius(), shape_.getRadius());

    // Calculate the center of the window
    // const Vector2 center(screen_size_.x / 2, screen_size_.y / 2);
        
    // Position the shape at the center of the window
    // shape_.setPosition(center.x + a.x, center.y + a.y);
}
