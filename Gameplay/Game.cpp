#include "Game.h"

#include <iostream>

#include "../Objects/Entity.h"

Game::Game()
{
    start_game();
}

Game::~Game()
{
    end_game();
}

void Game::start_game()
{
    std::cout << "Game has start!" << "\n";
    
    window_.create(sf::VideoMode(screen_size_.x, screen_size_.y), "Speed Racer!");
    window_.setFramerateLimit(60);

    background_color_.r = background_color_value_;
    background_color_.g = background_color_value_;
    background_color_.b = background_color_value_;

    clock_.restart();
    shape_.setRadius(10);
    shape_.setFillColor(sf::Color::Cyan);
}

void Game::loop_game()
{    
    while (window_.isOpen())
    {
        sf::Event event;
    
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
                return;
            }
        }
        
        int input = 0;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            input = -10;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            input = 10;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            input = -50;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            input = 50;
        }

        // if (delta_time() >= 5)
        // {
        //     window_.close();
        //     return;
        // }
    
        shape_.setRadius(shape_.getRadius() + delta_time());

        // Set the origin of the circle shape to its center
        shape_.setOrigin(shape_.getRadius(), shape_.getRadius());

        // Calculate the center of the window
        const Vector2 center(screen_size_.x / 2, screen_size_.y / 2);

        // Position the shape at the center of the window
        shape_.setPosition(center.x + input, center.y + input);
        
        window_.clear(background_color_);
        window_.draw(shape_);

        sf::Font font;
        if (!font.loadFromFile("ArcadeNormal-ZDZ.ttf"))
        {
            // error
        }
    
        sf::Text text;
        text.setFont(font);
        text.setString("Hello world");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        window_.draw(text);

        window_.display();
    }
}

void Game::end_game()
{
    std::cout << "Game has ended!" << "\n";
}

float Game::delta_time() const
{
    return clock_.getElapsedTime().asSeconds();
}
