#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include "util.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v = {1,2,3};
    cout << stringify_vector(v) << endl;
    return 0;
}