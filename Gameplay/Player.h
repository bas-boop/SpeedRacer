#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "Hitable.h"
#include "../Objects/Sprite.h"
#include "../Math/Collider.h"

class Player final : Entity
{
public:
    Player();
    ~Player() override;

    Vector2 get_position() const override;
    Vector2 get_center_position() const override;
    void draw_self(sf::RenderWindow& w);
    void handel_collision(const Collider& other);

    void update();
    void set_position(Vector2& target_pos) override;

private:
    sf::CircleShape shape_;
    Sprite sprite_;
    Hitable hitable_;

    float speed_ = 6;
    float start_height_ = 100;
};
