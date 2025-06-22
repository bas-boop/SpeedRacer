#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Hittable.h"
#include "Obstacle.h"
#include "../Math/ForceBody.h"

Game::Game()
    : road1_(0),
      road2_(-400),
      road3_(-800),
      obstacle1_(Vector2(0.2f, 0)),
      obstacle2_(Vector2(0, 400)),
      obstacle3_(Vector2(1200, 800))
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

    player_.clock = clock_;
    clock_.restart();
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

        if (update_entities())
            draw();
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

bool Game::update_entities()
{
    const bool game_can_be_over = !is_game_over_ &&
            (player_.handel_collision(obstacle1_.get_collider())
            || player_.handel_collision(obstacle2_.get_collider())
            || player_.handel_collision(obstacle3_.get_collider()))
            && score_ > 0;
    
    if (game_can_be_over)
    {            
        is_game_over_ = true;
        end_screen_.setup(window_.getSize(), score_);
    }

    if (is_game_over_)
    {
        window_.clear(background_color_);
        end_screen_.draw(window_);
        window_.display();

        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed
                || event.type == sf::Event::KeyPressed)
                window_.close();
        }

        return false;
    }
        
    road1_.update();
    road2_.update();
    road3_.update();
    player_.update();
    obstacle1_.update();
    obstacle2_.update();
    obstacle3_.update();

    const float player_y = player_.get_position().y;

    auto try_score = [&](Obstacle& obs)
    {
        if (!obs.has_scored()
            && obs.get_position().y > player_y)
        {
            score_++;
            score_text_.update(score_);
            obs.mark_scored();
        }
    };

    try_score(obstacle1_);
    try_score(obstacle2_);
    try_score(obstacle3_);

    return true;
}

void Game::draw()
{
    window_.clear(background_color_);
        
    road1_.draw_self(window_);
    road2_.draw_self(window_);
    road3_.draw_self(window_);
    player_.draw_self(window_);
    obstacle1_.draw_self(window_);
    obstacle2_.draw_self(window_);
    obstacle3_.draw_self(window_);
        
    score_text_.draw(window_);
    window_.display();
}
