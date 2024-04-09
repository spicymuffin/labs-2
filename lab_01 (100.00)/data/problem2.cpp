#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/**********************/
/*******Problem 2******/
/**********************/
/* ID:                */
/* NAME:              */
/**********************/

int main(){
	int loopNum;

	ifstream infile("input2.txt");
	
	infile >> loopNum;
	for (int i = 0; i < loopNum; i++) {
		int a_x, a_y;
		int b_x, b_y;
		int c_x, c_y;
		infile >> a_x >> a_y;
		infile >> b_x >> b_y;
		infile >> c_x >> c_y;

		int moveNum;
		infile >> moveNum;

		for (int j = 0; j < moveNum; ++j) {
			char target;
			char dir;
			infile >> target >> dir;

			/*
				Your Code
				Print into terminal
				ex) cout << "Hello, World!\n";
			*/
		}

		cout << "Position of A: (" << a_x << ", " << a_y << ")" << endl;
		cout << "Position of B: (" << b_x << ", " << b_y << ")" << endl;
		cout << "Position of C: (" << c_x << ", " << c_y << ")" << endl;
        
	}

	infile.close();

	return 0;
}
