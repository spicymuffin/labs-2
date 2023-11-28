#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string firstName;
    string middleName;
    string lastName;

    getline(cin, firstName);
    getline(cin, middleName);
    getline(cin, lastName);

    if (middleName != "")
    {
        cout << lastName << ", " << firstName << ", " << middleName << "." << endl;
    }
    else
    {
        cout << lastName << ", " << firstName << "." << endl;
    }
}