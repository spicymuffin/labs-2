#include <iostream>
#include <vector>
#include <string>

#include "vector2d.h"

using namespace std;

int main(int argc, char *argv[])
{
    Vector2D a;
    Vector2D b;

    a.setX(5);
    a.setY(6);

    Vector2D c(a);

    cout << c << endl;
    cout << ++a << endl;

    int int_a = 0;
    int int_b = 0;

    int &ref_int_a = int_a;

    int *ptr_int_a = &int_a;
    int *ptr_int_b = &int_b;

    char char_a = 'A';
    char char_b = 'b';

    cout << ptr_int_a + 1 << endl;

    //cout << static_cast<int>(char_a) << endl;

    return 0;
}