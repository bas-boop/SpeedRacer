#pragma once

#include <SFML/Graphics.hpp>

class ScoreText {
public:
    ScoreText();
    void update(int newScore);
    void draw(sf::RenderWindow& window) const;

private:
    int score_;
    sf::Text text_;
    sf::Font font_;
};
