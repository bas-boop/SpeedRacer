#include "../Gameplay/Game.h"
#include "Basics.h"

// based on NewtonRaphson
float Basics::sqrt(const float n)
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
