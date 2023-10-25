#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Vector2D
{
public:
	Vector2D(float _x, float _y) : x(_x), y(_y) {};

	Vector2D() : x(0), y(0) {};
	
	void setx(int _x) { x = _x; };
	void sety(int _y) { y = _y; };

	const float getx() { return x; };
	const float gety() { return y; };

	
	const Vector2D subtract(Vector2D a, Vector2D b)
	{
		return Vector2D(a.getx() - b.getx(), a.gety() - b.gety());
	};

	const Vector2D add(Vector2D a, Vector2D b)
	{
		return Vector2D(a.getx() + b.getx(), a.gety() + b.gety());
	};

	const float getMagnitude()
	{
		return pow((x*x) + (y*y), 0.5);
	}

	void shift(float _dx, float _dy)
	{
		x += _dx;
		y += _dy;
	};

	string stringify()
	{
		return "x: " + to_string(x) + "\ny: " + to_string(y) + "\nmagnitude: " + to_string(getMagnitude());
	};

	
private:
	float x = 0;
	float y = 0;
};


class Canvas
{
public:
	Canvas();
	
private:
	static Vector2D points[1024];
	static int current_index;
};

int main(int argc, char *argv[])
{
	Vector2D a, b;
	a = Vector2D();
	b = Vector2D(1, 2);

	cout << b.stringify() << endl;
	cout << a.stringify() << endl;

	return 0;
}