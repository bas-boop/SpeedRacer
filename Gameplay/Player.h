#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "Hitable.h"
#include "../Objects/Sprite.h"
#include "../Math/Collider.h"
#include "../Math/Force.h"

class Player final : Entity
{
public:
    Player();
    ~Player() override;

    Vector2 get_position() const override;
    Vector2 get_center_position() const override;
    void draw_self(sf::RenderWindow& w);
    void handel_collision(const Collider& other);

    void update(Force force);
    void set_position(Vector2& target_pos) override;

private:
    sf::CircleShape shape_;
    Sprite sprite_;
    Hitable hitable_;
    Vector2 veclocity_;

    float speed_ = 0.001f;
    float start_height_ = 100;
};
