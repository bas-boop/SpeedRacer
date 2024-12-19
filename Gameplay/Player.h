#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "../Objects/Sprite.h"

class Player final : Sprite
{
public:
    Player();
    ~Player() override;

    Vector2 get_position() const override;
    Vector2 get_center_position() const override;
    void draw_self(sf::RenderWindow& w) override;

    void update();
    void set_position(Vector2& target_pos) override;

private:
    sf::CircleShape shape_;

    float speed_ = 6;
    float start_height_ = 600;
};
