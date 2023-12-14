#include "Entertainer/Singer/Singer.h"

#include <string>

using namespace std;

Music Singer::getFavoriteSong() { return _favoriteSong; }

void Singer::setFavoriteSong(Music favoriteSong) { _favoriteSong = favoriteSong; }

string Singer::getJobName() { return "singer"; }