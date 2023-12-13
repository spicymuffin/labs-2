#include "Entertainer/Artist.h"
#include "Entertainer/MBTI.h"

#include <string>

using namespace std;

// define getName
string Artist::getName() { return _name; }

// define getMBTI
MBTI Artist::getMBTI() { return _mbti; }

// define setMBTI
void Artist::setMBTI(MBTI mbti) { _mbti = mbti; }

// define getPopularity
int Artist::getPopularity() { return _popularity; }

// define setPopularity
void Artist::setPopularity(int popularity) { _popularity = popularity; }