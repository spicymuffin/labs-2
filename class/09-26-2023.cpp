#include <iostream>

using namespace std;

class Rectangle
{
public:
    void setHeight(int _height)
    {
        height = _height;
    }

    void setLength(int _length)
    {
        length = _length;
    }

    int getHeight()
    {
        return height;
    }

    int getLength()
    {
        return length;
    }

    int getSize()
    {
        return height * length;
    }

private:
    int height;
    int length;
};

int main()
{
    Rectangle rect0;

    rect0.setHeight(3);
    rect0.setLength(6);

    cout << rect0.getSize() << endl;

    return 0;
}