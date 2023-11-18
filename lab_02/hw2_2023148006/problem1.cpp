/*!
 *
 * \file problem1.cpp
 * \brief Implement Collatz Conjecture
 *
 * Collatz Conjecture
 *
 * Calculate the Collatz algorithm,
 * and print the calculation process.
 *
 * In the input file, the first row is the number of iterations.
 * Starting from the second row, each line represents the number N to be calculated.
 *
 * The output file must contain the numbers from the calculation process.
 *
 * It is recommended that you write your own code on the lines provided,
 * but you are free to do so by modifying the skeleton code.
 */

#include <iostream>
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const string InputFilePath = "input1.txt";
const string OutputFilePath = "output1.txt";
//---------------------------------------------------------------------------
int main(void)
{
    ifstream Ifs{InputFilePath};
    if (Ifs.fail())
    {
        cerr << "Failed to open input file\n";
        return 0;
    }
    ofstream Ofs{OutputFilePath};

    int C = 0;
    int N = 0;

    Ifs >> C;
    // repeat C times
    for (int i = 0; i < C; i++)
    {
        // get N
        Ifs >> N;
        // output it
        Ofs << N << endl;
        // calculate T(N) until N becomes N
        while (N != 1)
        {
            // if even
            if (N % 2 == 0)
            {
                // divide by 2
                N /= 2;
            }
            // if odd
            else
            {
                // mult by 3, add 1
                N = N * 3 + 1;
            }
            // output N
            Ofs << N << endl;
        }
    }

    return 0;
}
//---------------------------------------------------------------------------