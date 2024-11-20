#pragma once

#include "../Math/Vector2.h"

class Entity
{
public:
    Vector2 get_position() const;
    Vector2 get_center_position() const;
    
private:
    Vector2 position_ = Vector2(0,0);
};
