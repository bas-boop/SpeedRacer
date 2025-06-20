#include "Player.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

#include "../Math/ForceBody.h"

Player::Player()
{
    sprite_.set_sprite_path("Assets/Player.png");
    const Vector2 start_position (0.5f, start_height_);
    set_position(start_position);
    hittable_.set_radius(7);
    current_speed_ = speed_;
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
    hittable_.draw(w);
}

void Player::handel_collision(const Collider& other)
{
    if (hittable_.get_collider().is_colliding(other))
    {
        std::cout << "collision \n";
    }
}

void Player::update()
{
    Vector2 input = Vector2::zero;
    
    input.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    //input.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    
    if (input.x != 0)
        input = input.normalize();

    add_force(input);
    update_physics();
    
    sprite_.set_position(get_position());
    hittable_.set_position(get_position());
}

void Player::set_position(const Vector2& target_pos)
{
    ForceBody::set_position(target_pos);
}
