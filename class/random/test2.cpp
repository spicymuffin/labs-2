#include <iostream>
#include <string>

using namespace std;

int &returnptr()
{
    int *a = new int;
    *a = 2;
    return *a;
}

int main(int argc, char *argv[])
{
    int *ptr1, *ptr2;
    int a, b;

    a = 0;
    b = 0;

    ptr1 = &a;
    ptr2 = &b;

    cout << ptr1 << endl;

    ptr1 = returnptr();

    cout << *ptr1 << endl;

    return 0;
}