#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string relativeTestCaseDirectory;
    string relativeExecutableDirectory;

    ofstream outfile;
    outfile.open("output1.txt");

    cin >> relativeExecutableDirectory;
    relativeExecutableDirectory += "<input1.txt >output1.txt";
    const char *c = relativeExecutableDirectory.c_str();
    std::system(c);

    outfile.close();

    return 0;
}