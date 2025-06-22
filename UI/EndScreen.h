#pragma once
#include <SFML/Graphics.hpp>

class EndScreen {
public:
    EndScreen(); // Default constructor
    void setup(const sf::Vector2u& window_size, int score); // New method
    void draw(sf::RenderWindow& window) const;

private:
    sf::Text text_;
    sf::Font font_;
};
