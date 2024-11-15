#include "Game.h"

void Game::start_game()
{
    window_.create(sf::VideoMode(400, 400), "Speed Racer!");
    
    clock.restart();
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
                window_.close();
        }

        shape_.setRadius(shape_.getRadius() + delta_time() / 100);
        
        window_.clear();
        window_.draw(shape_);
        window_.display();
    }
}

float Game::delta_time()
{
    return clock.getElapsedTime().asSeconds();
}
