#include "Sprite.h"

#include <iostream>


Sprite::Sprite()
{
    if (!texture_.loadFromFile("Assets/Cucumber.png"))
    {
        std::cerr << "Failed to load texture! - " << this << "\n";
    }
    
    sprite_.setTexture(texture_);
    sprite_.setPosition(position_.x, position_.y);
}

void Sprite::draw_self(sf::RenderWindow& w)
{
    sprite_.setPosition(position_.x, position_.y);
    w.draw(sprite_);
}

Vector2 Sprite::get_position() const
{
    return Entity::get_position();
}

void Sprite::set_position(Vector2& target_pos)
{
    Entity::set_position(target_pos);
}
