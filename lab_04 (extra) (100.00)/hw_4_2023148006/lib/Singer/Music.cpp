#include "Entertainer/Singer/Music.h"

#include <string>

using namespace std;

// implement getMusicName
string Music::getMusicName() { return _name; }

// implement setMusicName
void Music::setMusicName(string name) { _name = name; }

// implement getLength (returns in seconds)
int Music::getLength() { return _min * 60 + _sec; }

// implement setLength
void Music::setLength(int min, int sec)
{
    _min = min;
    _sec = sec;
}