#pragma once

struct Vector2
{
    Vector2();
    Vector2(float x, float y);

    float x;
    float y;

    static Vector2 zero;
    static Vector2 one;
    static Vector2 half;
    
    Vector2 operator+(Vector2 v);
    Vector2 operator-(Vector2 v);
    Vector2 operator*(Vector2 v);
    Vector2 operator/(Vector2 v);

    Vector2& operator+=(const Vector2* v);
    Vector2& operator-=(const Vector2* v);
    Vector2& operator*=(const Vector2* v);
    Vector2& operator/=(const Vector2* v);

    Vector2& operator+=(const Vector2& v);
    Vector2& operator-=(const Vector2& v);
    Vector2& operator*=(const Vector2& v);
    Vector2& operator/=(const Vector2& v);

    Vector2 operator+(const float f) const;
    Vector2 operator-(const float f) const;
    Vector2 operator*(const float f) const;
    Vector2 operator/(const float f) const;

    Vector2& operator+=(const float f);
    Vector2& operator-=(const float f);
    Vector2& operator*=(const float f);
    Vector2& operator/=(const float f);

    float magnitude() const;
    Vector2 normalize() const;
};
