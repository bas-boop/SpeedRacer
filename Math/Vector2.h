﻿#pragma once
#include <iosfwd>

struct Vector2
{
    Vector2();
    Vector2(float x, float y);
    Vector2(const Vector2& v);

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
    
    Vector2 operator-(const Vector2& other) const;
    bool operator==(const Vector2& other) const;

    float magnitude() const;
    float magnitude_squared() const;
    
    Vector2 normalize() const;
    Vector2 inverted() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Vector2& vector2);
    Vector2 operator+(const Vector2& vector2) const;
};
