#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace test_namespace_1
{
    int max(int a, int b)
    {
        cout << a << " <1> " << b << endl;
        return a;
    }
}

namespace test_namespace_2
{
    int max(int a, int b)
    {
        cout << a << " <2> " << b << endl;
        return b;
    }
}

using namespace test_namespace_1;
using namespace test_namespace_2;

int main(int argc, char *argv[])
{
    int *p1, p2, p3;
    p2 = 3;
    test_namespace_1::max(1, 2);
}