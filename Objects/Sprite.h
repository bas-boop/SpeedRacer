#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Sprite : Entity
{
public:
    Sprite();
    
    void draw_self(sf::RenderWindow& w);

    Vector2 get_position() const override;
    void set_position(Vector2& target_pos) override;
    
private:
    sf::Texture texture_;
    sf::Sprite sprite_;
};
