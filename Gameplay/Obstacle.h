#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "Hittable.h"
#include "../Math/ForceBody.h"

class Obstacle final : public ForceBody
{
public:
    Obstacle(const Vector2& spawn_position);
    ~Obstacle();

    void update();
    void draw_self(sf::RenderWindow& window);
    Collider get_collider();

private:
    enum class Direction { Left, Right };
    Direction direction_;

    Vector2 spawn_position_;
    Vector2 respawn_position_;

    Hittable hit_;

    float move_force_ = 50;
    float vertical_speed_ = 5.0f;
    float replace_position_threshold_ = 800;
    float replace_position_ = -800;
    float replace_randomness_ = 300;

    sf::Clock vertical_timer_;
    float vertical_delay_ = 3;
    bool vertical_movement_enabled_ = false;
};
