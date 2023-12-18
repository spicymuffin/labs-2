#include <iostream>
#include <string>

using namespace std;

class HotDogStand
{
public:
    HotDogStand(int _ID);
    HotDogStand(int _ID, int _hotDogsSold);

    void JustSold();
    void PrintData();
    static void PrintTotal();
    const static int GetTotalSold();
    static void JustSoldTotal();
    const int GetSold();
    const int GetID();
    void SetSold(int _hotDogsSold);
    void SetID(int _ID);

private:
    int ID;
    int hotDogsSold;
    static int hotDogsSoldTotal;
};