#include <iostream>
using namespace std;

class Student
{
public:
    Student(double _width, double _height) : width(_width), height(_height){};
    Student() : width(5.0), height(5.0){};

    void setWidth(double _width) { width = _width; };
    void setHeight(double _height) { height = _height; };

    double computeArea() { return width * height; };
    void displayRectangleDetails()
    {
        cout << "width: " << width << endl;
        cout << "height: " << height << endl;
        cout << "area: " << computeArea() << endl;
    }

private:
    double width;
    double height;
};

int main(int argc, char *argv[])
{
    cout << "enter: " << endl;
    double w, h;
    cin >> w >> h;
    Student rect(w, h);
    rect.displayRectangleDetails();
    return 0;
}
