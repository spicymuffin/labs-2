#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

using namespace std;

class Vector3D
{
public:
    Vector3D();
    Vector3D(float _x, float _y, float _z);

    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float _x);
    void setY(float _y);
    void setZ(float _z);

    float getMagnitude() const;

    const Vector3D getNormalized() const;

    const Vector3D operator++(int);
    Vector3D &operator++();

    const Vector3D operator--(int);
    Vector3D &operator--();

    friend const Vector3D operator+(const Vector3D &lhs, const Vector3D &rhs);
    friend const Vector3D operator-(const Vector3D &lhs, const Vector3D &rhs);

    friend const Vector3D operator-(const Vector3D &rhs);
    friend const Vector3D operator+(const Vector3D &rhs);

    friend const bool operator==(const Vector3D &lhs, const Vector3D &rhs);

    friend ostream &operator<<(ostream &outputStream, const Vector3D &rhs);
    friend istream &operator>>(istream &inputStream, Vector3D &rhs);

private:
    float x;
    float y;
    float z;
};

#endif