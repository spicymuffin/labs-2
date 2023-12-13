#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
    A(vector<int> gay)
    {
        aaa = gay;
    }

    vector<int> getvect()
    {
        return aaa;
    }

    vector<int> aaa;
};

int main()
{
    A a({1, 2, 3});
    cout << a.aaa[0] << endl;

    a.getvect()[0] -= 2;
s
    cout << a.getvect()[0] << endl;
}