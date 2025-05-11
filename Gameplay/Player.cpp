#include "Player.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

#include "../Math/ForceBody.h"

Player::Player()
{
    sprite_.set_sprite_path("Assets/Player.png");
    Vector2 a (0.5f, start_height_);
    set_position(a);
    hitable_.set_radius(7);
    speed_ = speed;
}

Player::~Player()
{
    ForceBody::~ForceBody();
}

Vector2 Player::get_position() const
{
    return ForceBody::get_position();
}

Vector2 Player::get_center_position() const
{
    return ForceBody::get_center_position();
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
    Vector2 input = Vector2::zero;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        input.x = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        input.x = 1;

    std::cout << "Input: " << input << "\n";

    add_force(input * 5);
    update_physics();

    std::cout << "pos: " << ForceBody::get_position() << "\n";

    sprite_.set_position(ForceBody::get_position());
    hitable_.set_position(ForceBody::get_position());
}

void Player::set_position(const Vector2& target_pos)
{
    ForceBody::set_position(target_pos);
}
