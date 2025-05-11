#pragma once
#include "../Objects/Entity.h"

class Collider final : Entity
{
public:
    Collider();
    explicit Collider(float radius_target);
    ~Collider();
    
    bool is_colliding(const Collider& other) const;
    void set_position(const Vector2& vector2) override;
    void set_radius(float target);

private:
    float radius_ = 0.5f; 
};
