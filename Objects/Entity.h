#pragma once

#include "../Math/Vector2.h"

class Entity
{
public:
    virtual ~Entity();
    
    Vector2 get_position() const;
    virtual  Vector2 get_center_position();
    
private:
    Vector2 position_ = Vector2::zero;
};
