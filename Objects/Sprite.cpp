#include "Sprite.h"

#include <iostream>

Sprite::Sprite()
{
    set_texture();
}

Sprite::~Sprite()
{
    Entity::~Entity();
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

Vector2 Sprite::get_center_position() const
{
    return  Entity::get_center_position();
}

sf::Sprite Sprite::get_sprite() const
{
    return sprite_;
}

void Sprite::set_position(const Vector2& target_pos)
{
    Entity::set_position(target_pos);
}

void Sprite::set_sprite_path(const std::string& path)
{
    sprite_path_ = path;
    set_texture();
}

void Sprite::set_texture()
{
    if (!texture_.loadFromFile(sprite_path_))
    {
        std::cerr << "Failed to load texture! - " << this << "\n";
    }
    
    sprite_.setTexture(texture_);
}
