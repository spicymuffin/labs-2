#include "Entertainer/Actor/Actor.h"
#include "Entertainer/Artist.h"
#include "Entertainer/Actor/Drama.h"

using namespace std;

// de
Actor::Actor(string name) : Artist(name) {}

Actor::~Actor() {}

Drama Actor::getMasterpiece() { return _masterpiece; }

void Actor::setMasterpiece(Drama masterpiece) { _masterpiece = masterpiece; }

string Actor::getJobName() { return "Actor"; }