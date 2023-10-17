#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/**********************/
/*******Problem 1******/
/**********************/
/* ID:                */
/* NAME:              */
/**********************/

int main(){
	int loopNum;

	ofstream outfile;
	outfile.open("output1.txt");

	cout << "Enter the number of interations for the loop: ";
	cin >> loopNum;

	for (int i = 0; i < loopNum; i++) {
		int a, b, c;
		int x0, x1;
		cout << "Enter the coefficients of the equation [y = ax^2 + bx + c]" << endl;
		cout << "a: "; cin >> a;
		cout << "b: "; cin >> b;
		cout << "c: "; cin >> c;
		cout << "Enter the value of x0 and x1" << endl;
		cout << "x0: "; cin >> x0;
		cout << "x1: "; cin >> x1;

        // To fix the precision of floating numbers
        outfile << setprecision(3) << fixed;

		/*
			Your Code
			Write into outfile
			ex) outfile << "Hello, World!\n";

			Type casting
			ex) double d = 2;			// d = 2.0
			double d = (double)2;		// d = 2.0
			double d = 5 / 2;			// d = 2.0
			double d = (double)5 / 2;	// d = 2.5
		*/
	}

	outfile.close();

	return 0;
}
