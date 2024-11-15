#pragma once
#include "SFML/Graphics.hpp"

class Game
{
public:
    void start_game();

    void loop_game();

    float delta_time();

private:
    sf::RenderWindow window_;
    sf::Clock clock;
    sf::CircleShape shape_;
};
