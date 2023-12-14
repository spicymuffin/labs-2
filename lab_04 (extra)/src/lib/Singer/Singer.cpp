#include "Entertainer/Singer/Singer.h"

#include <string>

using namespace std;

Singer::Singer(string name) : Artist(name) {}

Singer::~Singer() {}

Music Singer::getFavoriteSong() { return _favoriteSong; }

void Singer::setFavoriteSong(Music favoriteSong) { _favoriteSong = favoriteSong; }

string Singer::getJobName() { return "Singer"; }