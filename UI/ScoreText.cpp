#include "ScoreText.h"
#include <iostream>

ScoreText::ScoreText() : score_(0)
{
    if (!font_.loadFromFile("Assets/ArcadeNormal-ZDZ.ttf"))
        std::cerr << "Failed to load font!\n";

    text_.setFont(font_);
    text_.setCharacterSize(24);
    text_.setFillColor(sf::Color::White);
    text_.setPosition(10, 10);
    text_.setString("Score: 0");
}

void ScoreText::update(int newScore)
{
    score_ = newScore;
    text_.setString("Score: " + std::to_string(score_));
}

void ScoreText::draw(sf::RenderWindow& window) const
{
    window.draw(text_);
}
