#include "Road.h"

Road::Road()
{
    sprite_.set_sprite_path("Assets/Cucumber.png");
    position_.y = -10;

    Entity::Entity();
}

Road::Road(const float target_start_height)
{
    sprite_.set_sprite_path("Assets/Cucumber.png");
    position_.y = -target_start_height;

    Entity::Entity();
}

Road::~Road()
{
    Entity::~Entity();
}

void Road::update()
{
    position_.y += speed_;

    if (position_.y >= replace_position_threshold_)
        position_.y = replace_position_;
    
    sprite_.set_position(position_);
}

void Road::draw_self(sf::RenderWindow& w)
{
    sprite_.draw_self(w);
}
