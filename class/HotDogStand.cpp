#include "HotDogStand.h"
#include <iostream>
#include <string>

HotDogStand::HotDogStand(int _ID) : ID(_ID), hotDogsSold(0){};
HotDogStand::HotDogStand(int _ID, int _hotDogsSold) : ID(_ID), hotDogsSold(_hotDogsSold){};

void HotDogStand::JustSold()
{
    hotDogsSold += 1;
    HotDogStand::JustSoldTotal();
}

void HotDogStand::PrintData()
{
    cout << "ID: " << ID << endl;
    cout << "hot dogs sold: by " << ID << ": " << hotDogsSold << endl;
}

void HotDogStand::PrintTotal()
{
    cout << "total hotdogs sold: " << hotDogsSoldTotal << endl;
}

const int HotDogStand::GetTotalSold() { return hotDogsSoldTotal; };
void HotDogStand::JustSoldTotal() { hotDogsSoldTotal += 1; };

const int HotDogStand::GetSold() { return hotDogsSold; };
const int HotDogStand::GetID() { return ID; };

void HotDogStand::SetSold(int _hotDogsSold) { hotDogsSold = _hotDogsSold; };
void HotDogStand::SetID(int _ID) { ID = _ID; };

int HotDogStand::hotDogsSoldTotal = 0;

