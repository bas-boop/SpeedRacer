#include "Game.h"
#include "Player.h"

#include <iostream>

Game::Game()
    : road1_(0),
      road2_(-400),
      road3_(-800)
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

        // if (delta_time() >= 5)
        // {
        //     window_.close();
        //     return;
        // }

        road1_.update();
        road2_.update();
        road3_.update();
        player_.update();

        window_.clear(background_color_);

        // for (int i = 0; i < sprites_.size(); ++i)
        // {
        //     window_.draw(sprites_.at(i).get_sprite());
        // }
        
        road1_.draw_self(window_);
        road2_.draw_self(window_);
        road3_.draw_self(window_);
        player_.draw_self(window_);
        
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
