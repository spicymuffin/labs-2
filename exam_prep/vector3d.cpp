#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "vector3d.h"

using namespace std;

Vector3D::Vector3D() : x(0), y(0), z(0) {}
Vector3D::Vector3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

float Vector3D::getX() const { return x; }
float Vector3D::getY() const { return y; }
float Vector3D::getZ() const { return z; }

void Vector3D::setX(float _x) { x = _x; }
void Vector3D::setY(float _y) { y = _y; }
void Vector3D::setZ(float _z) { z = _z; }

float Vector3D::getMagnitude() const { return pow(x * x + y * y + z * z, 0.5); }

const Vector3D Vector3D::getNormalized() const
{
    float magnitude = this->getMagnitude();
    float _x = x / magnitude;
    float _y = y / magnitude;
    float _z = z / magnitude;
    return Vector3D(_x, _y, _z);
}

const Vector3D operator+(const Vector3D &lhs, const Vector3D &rhs)
{
    return Vector3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

const Vector3D operator-(const Vector3D &lhs, const Vector3D &rhs)
{
    return Vector3D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

const Vector3D operator+(const Vector3D &rhs)
{
    return Vector3D(rhs.x, rhs.y, rhs.z);
}

const Vector3D operator-(const Vector3D &rhs)
{
    return Vector3D(-rhs.x, -rhs.y, -rhs.z);
}

ostream &operator<<(ostream &outputStream, const Vector3D &rhs)
{
    outputStream << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return outputStream;
}

istream &operator>>(istream &inputStream, Vector3D &rhs)
{
    inputStream >> rhs.x;
    inputStream >> rhs.y;
    inputStream >> rhs.z;
    return inputStream; // if we dont return input stream we cant "chain >>s"
}

// prefix. increment and return immediately
Vector3D &Vector3D::operator++()
{
    this->x += 1;
    this->y += 1;
    this->z += 1;
    return *this;
}

// postfix. increment variable but retutn not incremented
const Vector3D Vector3D::operator++(int)
{
    Vector3D copy(*this);
    operator++();
    return copy;
}

Vector3D &Vector3D::operator--()
{
    this->x -= 1;
    this->y -= 1;
    this->z -= 1;
    return *this;
}

const Vector3D Vector3D::operator--(int)
{
    Vector3D copy(*this);
    operator--();
    return copy;
}
