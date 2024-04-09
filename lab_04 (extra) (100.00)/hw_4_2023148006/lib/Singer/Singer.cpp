#include "Entertainer/Singer/Singer.h"

#include <string>

using namespace std;

// implement constructor
Singer::Singer(string name) : Artist(name) {}

// implement destructor
Singer::~Singer() {}

// implement getFavoriteSong
Music Singer::getFavoriteSong() { return _favoriteSong; }

// implement setFavoriteSong
void Singer::setFavoriteSong(Music favoriteSong) { _favoriteSong = favoriteSong; }

// implement getJobName
string Singer::getJobName() { return "Singer"; }