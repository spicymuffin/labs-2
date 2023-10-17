#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HotDogStand
{
public:
    HotDogStand(int _ID) : ID(_ID), hotDogsSold(0){};
    HotDogStand(int _ID, int _hotDogsSold) : ID(_ID), hotDogsSold(_hotDogsSold){};

    void JustSold()
    {
        hotDogsSold += 1;
        HotDogStand::justSoldTotal();
    }

    void printData()
    {
        cout << "ID: " << ID << endl;
        cout << "hot dogs sold: by " << ID << ": " << hotDogsSold << endl;
    }

    static void printTotal()
    {
        cout << "total hotdogs sold: " << hotDogsSoldTotal << endl;
    }

    static int getTotalSold() { return hotDogsSoldTotal; };

    static void justSoldTotal() { hotDogsSoldTotal += 1; };

    const int getSold() { return hotDogsSold; };
    const int getID() { return ID; };

    void setSold(int _hotDogsSold) { hotDogsSold = _hotDogsSold; };
    void setID(int _ID) { ID = _ID; };

private:
    int ID;
    int hotDogsSold;
    static int hotDogsSoldTotal;
};

int HotDogStand::hotDogsSoldTotal = 0;

int main(int argc, char *argv[])
{
    HotDogStand hts1(1), hts2(2, 50);

    cout << HotDogStand::getTotalSold() << endl;

    hts1.printData();
    hts2.printData();

    // HotDogStand::printTotal();
}