#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../Objects/Entity.h"
#include "../Math/Collider.h"

class Hittable : Entity
{
public:
    Hittable();
    ~Hittable();
    
    Collider get_collider();
    void draw(sf::RenderWindow& window);
    
    void set_position(const Vector2& target_pos) override;

    void set_radius(float target);
private:
    Collider collider_;
    sf::CircleShape circle_;

    bool should_show_ = true;
};
