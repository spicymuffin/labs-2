#include "Entertainer/Actor/Actor.h"
#include "Entertainer/Artist.h"
#include "Entertainer/Actor/Drama.h"

using namespace std;

Actor::Actor(string name) : Artist(name) {}

Drama Actor::getMasterpiece() { return _masterpiece; }

void Actor::setMasterpiece(Drama masterpiece) { _masterpiece = masterpiece; }

string Actor::getJobName() { return "actor"; }