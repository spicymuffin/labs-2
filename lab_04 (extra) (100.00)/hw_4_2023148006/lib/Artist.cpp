#include "Entertainer/Artist.h"
#include "Entertainer/MBTI.h"

#include <string>

using namespace std;

// implement getName
string Artist::getName() { return _name; }

// implement getMBTI
MBTI Artist::getMBTI() { return _mbti; }

// implement setMBTI
void Artist::setMBTI(MBTI mbti) { _mbti = mbti; }

// implement getPopularity
int Artist::getPopularity() { return _popularity; }

// implement setPopularity
void Artist::setPopularity(int popularity) { _popularity = popularity; }