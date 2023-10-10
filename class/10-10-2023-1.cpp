#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point
{
public:
    Point() : x(0), y(0){};

    Point(int _x, int _y) : x(_x), y(_y){};

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    };

    void print()
    {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }

    void setx(int _x) { x = _x; };
    void sety(int _y) { y = _y; };

    const int getx() { return x; };
    const int gety() { return y; };

private:
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    Point p1, p2(10, 5);
    // Point &p1 = Point(0, 1);
    // l-value r-value
    // p1 = Point(0, 1);

    p1.print();
    p2.print();

    p2.move(-10, -5);

    p1.print();
    p2.print();
};