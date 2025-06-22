#include "EndScreen.h"
#include <iostream>

EndScreen::EndScreen()
{
    if (!font_.loadFromFile("Assets/ArcadeNormal-ZDZ.ttf"))
        std::cerr << "Failed to load font for EndScreen!\n";

    text_.setFont(font_);
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::White);
}

void EndScreen::setup(const sf::Vector2u& window_size, const int score)
{
    text_.setString("Game Over\nScore: " + std::to_string(score));

    const sf::FloatRect text_bounds = text_.getLocalBounds();
    text_.setOrigin(text_bounds.width / 2, text_bounds.height / 2);
    text_.setPosition(static_cast<float>(window_size.x) / 2, static_cast<float>(window_size.y) / 2);
}

void EndScreen::draw(sf::RenderWindow& window) const
{
    window.draw(text_);
}
