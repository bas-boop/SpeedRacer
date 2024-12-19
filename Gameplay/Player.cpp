#include "Player.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

Player::Player()
{
    // sprite_path_ = "bla bal";
    position_.y = start_height_;
    position_ = Vector2::half;

    std::cout << sprite_path_ << "\n";
}

Player::~Player() = default;

Vector2 Player::get_position() const
{
    return Sprite::get_position();
}

Vector2 Player::get_center_position() const
{
    return Sprite::get_center_position();
}

void Player::draw_self(sf::RenderWindow& w)
{
    Sprite::draw_self(w);
}

void Player::update()
{
    int input = 0;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        input = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        input = -1;

    position_.x -= input * speed_;
}

void Player::set_position(Vector2& target_pos)
{
    Sprite::set_position(target_pos);
}
