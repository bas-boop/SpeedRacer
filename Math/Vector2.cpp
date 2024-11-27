#include "Vector2.h"

#include <iostream>

Vector2::Vector2()
{
    this->x = zero.x;
    this->y = zero.y;
}

Vector2::Vector2(const float x, const float y)
{
    this->x = x;
    this->y = y;
}

Vector2 Vector2::zero = {0, 0};

Vector2 Vector2::one = {1, 1};

Vector2 Vector2::half = {0.5f, 0.5f};

#pragma region VectorOperator

Vector2 Vector2::operator+(const Vector2 v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2 v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vector2 Vector2::operator*(const Vector2 v)
{
    x *= v.x;
    y *= v.y;
    return *this;
}

Vector2 Vector2::operator/(const Vector2 v)
{
    if (v.x == 0
            || v.y == 0)
    {
        std::cout << "Cant divide by zero\n";
        return *this;
    }
    
    x /= v.x;
    y /= v.y;
    return *this;
}

Vector2& Vector2::operator+=(const Vector2* v)
{
    x = x + v->x;
    y = y + v->y;
    
    return *this;
}

Vector2& Vector2::operator-=(const Vector2* v)
{
    x = x - v->x;
    y = y - v->y;
    
    return *this;
}

Vector2& Vector2::operator*=(const Vector2* v)
{
    x = x * v->x;
    y = y * v->y;
    
    return *this;
}

Vector2& Vector2::operator/=(const Vector2* v)
{
    x = x / v->x;
    y = y / v->y;
    
    return *this;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
    x = x + v.x;
    y = y + v.y;
    
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
    x = x - v.x;
    y = y - v.y;
    
    return *this;
}

Vector2& Vector2::operator*=(const Vector2& v)
{
    x = x * v.x;
    y = y * v.y;
    
    return *this;
}

Vector2& Vector2::operator/=(const Vector2& v)
{
    x = x / v.x;
    y = y / v.y;
    
    return *this;
}

#pragma endregion VectorOperator

#pragma region FloatOperator

Vector2 Vector2::operator+(const float f) const
{
    return Vector2(x + f, y + f);
}

Vector2 Vector2::operator-(const float f) const
{
    return Vector2(x - f, y - f);
}

Vector2 Vector2::operator*(const float f) const
{
    return Vector2(x * f, y * f);
}

Vector2 Vector2::operator/(const float f) const
{
    return Vector2(x / f, y / f);
}

Vector2& Vector2::operator+=(const float f)
{
    x = x + f;
    y = y + f;
    
    return *this;
}

Vector2& Vector2::operator-=(const float f)
{
    x = x - f;
    y = y - f;
    
    return *this;
}

Vector2& Vector2::operator*=(const float f)
{
    x = x * f;
    y = y * f;
    
    return *this;
}

Vector2& Vector2::operator/=(const float f)
{
    x = x / f;
    y = y / f;
    
    return *this;
}

#pragma endregion FloatOperator

float Vector2::magnitude() const
{
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalize() const
{
    const float m = magnitude();
    return Vector2(this->x / m, this->y / m);
}
