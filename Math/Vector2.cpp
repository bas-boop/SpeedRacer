#include "Vector2.h"

#include <iostream>

Vector2::Vector2(const float x, const float y)
{
    this->x = x;
    this->y = y;
}

void Vector2::add(const Vector2 v)
{
    x += v.x;
    y += v.y;
}

void Vector2::subtract(const Vector2 v)
{
    x -= v.x;
    y -= v.y;
}

void Vector2::multiply(const Vector2 v)
{
    x *= v.x;
    y *= v.y;
}

void Vector2::divide(const Vector2 v)
{
    if (v.x == 0
        || v.y == 0)
    {
        std::cout << "Cant divide by zero\n";
        return;
    }
    
    x /= v.x;
    y /= v.y;
}

Vector2 Vector2::operator+(const Vector2 v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vector2 Vector2::operator/(float i) const
{
    return Vector2(x/2, y/2);
}
