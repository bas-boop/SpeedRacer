#include "Player.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

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

void Player::update()
{
    int input = 0;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        input = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        input = -1;

    position_.x -= input * speed_;
    sprite_.set_position(position_);
    hitable_.set_position(position_);
}

void Player::set_position(Vector2& target_pos)
{
    Entity::set_position(target_pos);
}
