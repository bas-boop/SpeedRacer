#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Sprite final : public Entity
{
public:
    Sprite();
    ~Sprite() override;

    void draw_self(sf::RenderWindow& w);

    Vector2 get_position() const override;
    Vector2 get_center_position() const override;
    sf::Sprite get_sprite() const;

    void set_position(const Vector2& target_pos) override;

    void set_sprite_path(const std::string& path);

private:
    void set_texture();
    
    std::string sprite_path_ = "Assets/Cucumber.png";
    sf::Texture texture_;
    sf::Sprite sprite_;
};
