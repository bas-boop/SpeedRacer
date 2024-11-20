#include "Entity.h"

Vector2 Entity::get_position() const
{
    return position_;
}

Vector2 Entity::get_center_position() const
{
    // todo fix
    return position_ / 2;
}
