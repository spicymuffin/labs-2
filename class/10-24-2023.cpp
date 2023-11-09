#include <iostream>
#include <string>

using namespace std;

int fuck_off();

const int add(int &a, int &b);
int add_by_value(int a, int b = 7);
int array_test(int arr[]);

void swap_values(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
};

class Alen
{
public:
    Alen(int _index = 0)
    {
        index = _index;
    };

private:
    int balli_ege = 310;
    int index = -1;
};

int default_value_test(int a);

struct Gay
{
    int arr[100];
    int gay;
};

int main(int argc, char *argv[])
{
    float a = 100.0;
    int b = 1;

    int arr[10][10];
    int one[10] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0};
    Alen arr2[10];

    Alen g = Alen(10);

    Gay gay1 = {{}, 2};

    for (int i = 0; i < 10; i++)
    {
        arr2[i] = Alen(i);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = j + i * 10;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << static_cast<float>(b) + a << endl;
    cout << b++ << " " << b << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    };

    int d = 3;
    int c = 4;

    one[0] = 12;
    one[1] = 13;

    cout << one[0] << " " << one[1] << endl;
    swap_values(one[0], one[1]);
    cout << one[0] << " " << one[1] << endl;
    cout << gay1.arr[0] << " " << gay1.arr[1] << endl;
};

int default_value_test(int a = 7)
{
    cout << a << endl;
};