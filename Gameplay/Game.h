﻿#pragma once
#include "SFML/Graphics.hpp"
#include "../Math/Vector2.h"

class Game
{
public:
    Game();
    ~Game();

    void start_game();
    void loop_game();
    static void end_game();
    float delta_time() const;

private:
    sf::RenderWindow window_;
    sf::Color background_color_;
    const sf::Uint64 background_color_value_ = 80;
    sf::Clock clock_;
    sf::CircleShape shape_;

    Vector2 screen_size_ = Vector2(1280, 720);
};
