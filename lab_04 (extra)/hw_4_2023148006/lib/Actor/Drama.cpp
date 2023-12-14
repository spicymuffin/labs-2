#include "Entertainer/Actor/Drama.h"

#include <string>

using namespace std;

// implement getName
string Drama::getName() { return _name; }

// implement setName
void Drama::setName(string name) { _name = name; }

// implement getNumnSeries
int Drama::getNumSeries() { return _numSeries; }

// implement setNumSeries
void Drama::setNumSeries(int numSeries) { _numSeries = numSeries; }

// implement assignment operator
Drama &Drama::operator=(Drama drama)
{
    _name = drama.getName();
    _numSeries = drama.getNumSeries();
    return *this;
}