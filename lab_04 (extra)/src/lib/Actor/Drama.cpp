#include "Entertainer/Actor/Drama.h"

#include <string>

using namespace std;

string Drama::getName() { return _name; }

void Drama::setName(string name) { _name = name; }

int Drama::getNumSeries() { return _numSeries; }

void Drama::setNumSeries(int numSeries) { _numSeries = numSeries; }

// define assignment operator
Drama &Drama::operator=(Drama drama)
{
    _name = drama.getName();
    _numSeries = drama.getNumSeries();
    return *this;
}