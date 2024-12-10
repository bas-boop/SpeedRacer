#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "../Objects/Entity.h"

class Player final : Entity
{
public:
    Player();
    ~Player();
    
    Vector2 get_position() const override;
    Vector2 get_center_position() override;
    
    void update();

private:
    sf::CircleShape shape_;
    
    float speed_ = 1;
    float start_height_ = 600;
};
