#pragma once
#include <SFML/System/Clock.hpp>

#include "Vector2.h"
#include "../Objects/Entity.h"

class ForceBody : Entity
{
public:
    ~ForceBody() override;
    
    Vector2 add_force(const Vector2& inital_position, const Vector2 initial_velocity, const Vector2 acceratation) const; // unused
    void add_force(const Vector2&);
    void set_force(const Vector2&);
    void update_physics();

    Vector2 get_position() const override;
    Vector2 get_center_position() const override;
    void set_position(const Vector2& target_pos) override;
    
    sf::Clock clock;
    Vector2 current_force = Vector2::zero;

protected:
    float speed_ = 2.5f;    
    
private:
    Vector2 acceleration() const;
    
    Vector2 velocity_ = Vector2::zero;
    float max_speed_ = 10;

    float mass_ = 1;
    float friction_ = 0.1f;

    Vector2 acceleration_ = Vector2::zero;
    Vector2 grafity_ = Vector2::zero;
};
