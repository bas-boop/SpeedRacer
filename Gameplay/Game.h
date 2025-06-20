#pragma once
#include "Obstacle.h"
#include "Player.h"
#include "Road.h"
#include "../Math/ForceBody.h"
#include "SFML/Graphics.hpp"
#include "../Math/Vector2.h"

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
    // static sf::Clock clock_2;

    // std::vector<Sprite> sprites_;
    sf::Font font_;
    sf::Text text_;
    
    Player player_;
    Road road1_;
    Road road2_;
    Road road3_;
    Obstacle obstacle1_;
    Obstacle obstacle2_;
    Obstacle obstacle3_;
    
    Vector2 screen_size_ = Vector2(1280, 720);
};