#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    while (true)
    {
        cout << (rand() + 100) % 1000  << endl;
    }
}