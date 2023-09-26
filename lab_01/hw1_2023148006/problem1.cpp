#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/**********************/
/*******Problem 1******/
/**********************/
/* ID: 2023148006     */
/* NAME: Luigi Cussigh*/
/**********************/

double F(double x, int a, int b, int c);

int main()
{
    int loopNum;

    ofstream outfile;
    outfile.open("output1.txt");

    cout << "Enter the number of interations for the loop: ";
    cin >> loopNum;

    for (int i = 0; i < loopNum; i++)
    {
        int a, b, c;
        int x0, x1;
        cout << "Enter the coefficients of the equation [y = ax^2 + bx + c]" << endl;
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "c: ";
        cin >> c;
        cout << "Enter the value of x0 and x1" << endl;
        cout << "x0: ";
        cin >> x0;
        cout << "x1: ";
        cin >> x1;

        // To fix the precision of floating numbers
        outfile << setprecision(3) << fixed;

        // by FTC pt. 2:
        // write to file.
        outfile << F(x0, a, b, c) - F(x1, a, b, c) << endl;
    }

    outfile.close();

    return 0;
}

// calculates the value of the antiderivative
double F(double x, int a, int b, int c)
{
    return ((double)a * x * x * x / 3.0) + ((double)b * x * x / 2.0) + ((double)c * x);
}
