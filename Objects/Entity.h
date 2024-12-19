#pragma once

#include "../Math/Vector2.h"

class Entity
{
public:
    Entity();
    virtual ~Entity();
    
    virtual Vector2 get_position() const;
    virtual Vector2 get_center_position() const;

    virtual void set_position(Vector2& target_pos);
    
protected:
    Vector2 position_ = Vector2::zero;
};
