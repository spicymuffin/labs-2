#include <iostream>
#include <string>
#include "HotDogStand.h"

using namespace std;

int main(int argc, char *argv[])
{
    HotDogStand hts1(1), hts2(2, 50);

    cout << HotDogStand::GetTotalSold() << endl;

    hts1.PrintData();
    hts2.PrintData();

    // HotDogStand::printTotal();
}
