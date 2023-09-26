#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isDigit(char input);

int main()
{
    cout << isDigit('a') << endl;
    cout << isDigit('1') << endl;
}

bool isDigit(char input)
{
    if (48 <= (int)input && (int)input <= 57)
    {
        return true;
    }
    else
    {
        return false;
    }
}
