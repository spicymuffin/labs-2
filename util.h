#include <string>
#include <iostream>
#include <vector>

using namespace std;

string stringify_vector(vector<int> _vector, string _separator = " ")
{
    string output = "";
    for (int i = 0; i < _vector.size() - 1; i++)
    {
        output += to_string(_vector[i]) + _separator;
    }

    output += to_string(_vector[_vector.size() - 1]);

    return output;
}