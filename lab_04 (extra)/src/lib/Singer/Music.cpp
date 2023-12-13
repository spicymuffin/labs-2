#include "Entertainer/Singer/Music.h"

#include <string>

using namespace std;



string Music::getMusicName() { return _name; }


void Music::setMusicName(string name) { _name = name; }


int Music::getLength() { return _min * 60 + _sec; }


void Music::setLength(int min, int sec)
{
    _min = min;
    _sec = sec;
}