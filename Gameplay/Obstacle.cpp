#include "Obstacle.h"
#include <SFML/Graphics/RectangleShape.hpp>

#include "../Math/MathUtils.h"

Obstacle::Obstacle(const Vector2& spawn_position)
{
    spawn_position_ = spawn_position;
    set_position(spawn_position_);

    direction_ = spawn_position_.x > 640.0f ? Direction::Left : Direction::Right;
    respawn_position_ = Vector2(spawn_position_.x, replace_position_);
}

Obstacle::~Obstacle()
{
    ForceBody::~ForceBody();
}

void Obstacle::update()
{
    Vector2 force = Vector2::zero;

    if (direction_ == Direction::Left)
        force.x = -move_force_;
    else
        force.x = move_force_;

    if (direction_ == Direction::Left
        && position_.x < 0)
    {
        force.x = 0;
    }
    
    if (direction_ == Direction::Right
        && position_.x > 1280)
    {
        force.x = 0;
    }

    if (!vertical_movement_enabled_
        && vertical_timer_.getElapsedTime().asSeconds() >= (MathUtils::get_random(vertical_delay_, vertical_delay_ * 2)))
    {
        vertical_movement_enabled_ = true;
        clock.restart();
    }

    if (vertical_movement_enabled_)
    {
        position_.y += vertical_speed_;

        if (position_.y >= replace_position_threshold_)
        {
            position_.y = replace_position_;
            force.x = 0;
            set_force(Vector2::zero);
            respawn_position_.y = replace_position_ + MathUtils::get_random(0, replace_randomness_);
            set_position(respawn_position_);
            
            vertical_movement_enabled_ = false;
            vertical_timer_.restart();
            clock.restart();
        }

        add_force(force);
        update_physics();
    }

    hit_.set_position(position_);
}

void Obstacle::draw_self(sf::RenderWindow& window)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(20, 20));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(get_position().x, get_position().y);

    window.draw(shape);
    hit_.draw(window);
}

Collider Obstacle::get_collider()
{
    return hit_.get_collider();
}
