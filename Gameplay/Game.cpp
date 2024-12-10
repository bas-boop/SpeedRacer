#include "Game.h"
#include "Player.h"
#include "../Objects/Sprite.h"

#include <iostream>

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

    if (!font_.loadFromFile("Assets/ArcadeNormal-ZDZ.ttf"))
    {
        std::cerr << "Failed to load font!\n";
    }
    text_.setFont(font_);
    text_.setString("Speed Racer");
    text_.setCharacterSize(24);
    text_.setFillColor(sf::Color::Black);

    Vector2 a(100, -200);
        
    test_.set_position(a);
    
    player_ = Player();
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

        if (delta_time() >= 5)
        {
            window_.close();
            return;
        }
        
        // player_.update();

        window_.clear(background_color_);

        Vector2 a(test_.get_position() + Vector2::one);
        test_.set_position(a);
        
        test_.draw_self(window_);

        std::cout << test_.get_position() << "\n";
        
        window_.draw(text_);

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
