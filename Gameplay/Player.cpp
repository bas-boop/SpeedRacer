#include <SFML/Window/Keyboard.hpp>

#include "Player.h"
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

bool Player::handel_collision(const Collider& other)
{
    return hittable_.get_collider().is_colliding(other);
}

void Player::update()
{
    Vector2 input = Vector2::zero;
    input.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    
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
