#pragma once
#include <SFML/Graphics/CircleShape.hpp>

#include "Hittable.h"
#include "../Objects/Sprite.h"
#include "../Math/Collider.h"
#include "../Math/ForceBody.h"

class Player final : public ForceBody
{
public:
    Player();
    ~Player() override;

    Vector2 get_position() const override;
    Vector2 get_center_position() const override;
    void draw_self(sf::RenderWindow& w);
    void handel_collision(const Collider& other);

    void update();
    void set_position(const Vector2& target_pos) override;

    sf::Clock clock = ForceBody::clock;

private:
    sf::CircleShape shape_;
    Sprite sprite_;
    Hittable hittable_;
    Vector2 velocity_;

    float speed_ = 50;
    float start_height_ = 600;
};
