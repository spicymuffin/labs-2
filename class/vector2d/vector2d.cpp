#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "vector2d.h"

using namespace std;

Vector2D::Vector2D() : x(0), y(0) {}
Vector2D::Vector2D(float _x, float _y) : x(_x), y(_y) {}

float Vector2D::getX() const { return x; }
float Vector2D::getY() const { return y; }

void Vector2D::setX(float _x) { x = _x; }
void Vector2D::setY(float _y) { y = _y; }

float Vector2D::getMagnitude() const { return pow(x * x + y * y, 0.5); }

const Vector2D Vector2D::getNormalized() const
{
    float magnitude = this->getMagnitude();
    float _x = x / magnitude;
    float _y = y / magnitude;
    return Vector2D(_x, _y);
}

const Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs)
{
    return Vector2D(lhs.x + rhs.x, lhs.y + rhs.y);
}

const Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs)
{
    return Vector2D(lhs.x - rhs.x, lhs.y - rhs.y);
}

const Vector2D operator+(const Vector2D &rhs)
{
    return Vector2D(rhs.x, rhs.y);
}

const Vector2D operator-(const Vector2D &rhs)
{
    return Vector2D(-rhs.x, -rhs.y);
}