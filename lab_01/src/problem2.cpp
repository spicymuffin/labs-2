#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/**********************/
/*******Problem 2******/
/**********************/
/* ID: 2023148006     */
/* NAME: Luigi Cussigh*/
/**********************/

int main()
{
    int loopNum;

    ifstream infile("input2.txt");

    infile >> loopNum;
    for (int i = 0; i < loopNum; i++)
    {
        int a_x, a_y;
        int b_x, b_y;
        int c_x, c_y;
        infile >> a_x >> a_y;
        infile >> b_x >> b_y;
        infile >> c_x >> c_y;

        int moveNum;
        infile >> moveNum;

        for (int j = 0; j < moveNum; ++j)
        {
            char target;
            char dir;
            infile >> target >> dir;

            // pointers to chosen target.
            int *chosen_target_x;
            int *chosen_target_y;

            // tracks whether we have already detected malformed input
            bool malformed_input_notif = false;

            // validata target, set pointer refrence
            if (target == 'a')
            {
                chosen_target_x = &a_x;
                chosen_target_y = &a_y;
            }
            else if (target == 'b')
            {
                chosen_target_x = &b_x;
                chosen_target_y = &b_y;
            }
            else if (target == 'c')
            {
                chosen_target_x = &c_x;
                chosen_target_y = &c_y;
            }
            else
            {
                // if target invalid, raise flag
                malformed_input_notif = true;
            }

            // if flag is already raised then skip direction validation
            if (!malformed_input_notif)
            {
                // if direction is valid, update target coords by refrencing
                // it with a pointer
                if (dir == 'h')
                {
                    *chosen_target_x += -1;
                    *chosen_target_y += 0;
                }
                else if (dir == 'l')
                {
                    *chosen_target_x += 1;
                    *chosen_target_y += 0;
                }
                else if (dir == 'j')
                {
                    *chosen_target_x += 0;
                    *chosen_target_y += -1;
                }
                else if (dir == 'k')
                {
                    *chosen_target_x += 0;
                    *chosen_target_y += 1;
                }
                else
                {
                    // if direction is invalid show error msg
                    cout << "Wrong movement in iteration " << i << ", movement " << j << endl;
                }
            }
            else
            {
                // if target is invalid (flag raised) show error msg
                cout << "Wrong movement in iteration " << i << ", movement " << j << endl;
            }
        }
        cout << "Position of A: (" << a_x << ", " << a_y << ")" << endl;
        cout << "Position of B: (" << b_x << ", " << b_y << ")" << endl;
        cout << "Position of C: (" << c_x << ", " << c_y << ")" << endl;
    }

    infile.close();

    return 0;
}
