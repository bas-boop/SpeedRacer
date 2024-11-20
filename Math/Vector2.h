#pragma once

struct Vector2
{
    Vector2(float x, float y);
    
    float x;
    float y;

    void add(const Vector2 v);
    void subtract(Vector2 v);
    void multiply(const Vector2 v);
    void divide(const Vector2 v);

    Vector2 operator+(Vector2 v);
    Vector2 operator/(float i) const;
};
