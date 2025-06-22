#pragma once
#include "../Objects/Entity.h"
#include "../Objects/Sprite.h"

class Road final : Entity
{
public:
    Road();
    explicit Road(float target_start_height);
    ~Road() override;
    
    void update();
    void draw_self(sf::RenderWindow& w);

private:
    Sprite sprite_;
    float speed_ = 5;
    float replace_position_ = -800;
    float replace_position_threshold_ = 800;
};
