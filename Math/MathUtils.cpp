#include "../Gameplay/Game.h"
#include "MathUtils.h"
#include <random>


// based on NewtonRaphson
float MathUtils::sqrt(const float n)
{
    if (n < 0)
        return -1;

    if (n == 0
        || n == 1)
        return n;

    float x = n;
    float root;
    
    while (true)
    {
        constexpr float tolerance = 1e-6;
        root = 0.5f * (x + n / x);

        if (std::abs(root - x) < tolerance)
            break;
        
        x = root;
    }
    
    return root;
}

float MathUtils::get_random(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}
