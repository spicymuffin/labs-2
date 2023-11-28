#include <iostream>
using namespace std;

class Rectangle
{
public:
    Rectangle(double _width, double _height) : width(_width), height(_height){};
    Rectangle() : width(5.0), height(5.0){};

    void setWidth(double _width);
    void setHeight(double _height);

    double computeArea();
    void displayRectangleDetails();

private:
    double width;
    double height;
};

void Rectangle::setWidth(double _width)
{
    width = _width;
}

void Rectangle::setHeight(double _height)
{
    height = _height;
}

double Rectangle::computeArea()
{
    return width * height;
}

void Rectangle::displayRectangleDetails()
{
    cout << "width: " << width << endl;
    cout << "height: " << height << endl;
    cout << "area: " << computeArea() << endl;
}

int main(int argc, char *argv[])
{
    cout << "enter: " << endl;
    double w, h;
    cin >> w >> h;
    Rectangle rect(w, h);
    rect.displayRectangleDetails();
    return 0;
}
