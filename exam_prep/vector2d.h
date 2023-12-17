#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

using namespace std;

class Vector2D
{
public:
    Vector2D();
    Vector2D(float _x, float _y);

    float getX() const;
    float getY() const;

    void setX(float _x);
    void setY(float _y);

    float getMagnitude() const;

    const Vector2D getNormalized() const;

    const Vector2D operator++(int);
    Vector2D &operator++();

    const Vector2D operator--(int);
    Vector2D &operator--();

    friend const Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs);
    friend const Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs);

    friend const Vector2D operator-(const Vector2D &rhs);
    friend const Vector2D operator+(const Vector2D &rhs);

    friend const bool operator==(const Vector2D &lhs, const Vector2D &rhs);

    friend ostream &operator<<(ostream &outputStream, const Vector2D &rhs);
    friend istream &operator>>(istream &inputStream, Vector2D &rhs);

private:
    float x;
    float y;
};

#endif