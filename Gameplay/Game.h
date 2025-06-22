#pragma once
#include "Obstacle.h"
#include "Player.h"
#include "Road.h"
#include "SFML/Graphics.hpp"
#include "../Math/Vector2.h"
#include "../UI/ScoreText.h"
#include "../UI/EndScreen.h"

class Game
{
public:
    Game();
    ~Game();

    void start_game();
    void loop_game();
    static void end_game();
    float delta_time() const;
    
private:
    sf::RenderWindow window_;
    sf::Color background_color_;
    const sf::Uint64 background_color_value_ = 80;
    sf::Clock clock_;
    
    Player player_;
    Road road1_;
    Road road2_;
    Road road3_;
    Obstacle obstacle1_;
    Obstacle obstacle2_;
    Obstacle obstacle3_;

    EndScreen end_screen_;
    ScoreText score_text_;
    int score_ = -1;
    bool is_game_over_ = false;
    
    Vector2 screen_size_ = Vector2(1280, 720);
};