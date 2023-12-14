#include "Entertainer/Singer/StayC.h"
#include "Entertainer/Singer/Singer.h"

#include <string>
#include <vector>

using namespace std;

// idk why is Group definened in StayC.h but oh well...
// implement constructor
Group::Group(string name) : Artist(name) {}

// implement destructor
Group::~Group() {}

// implement getMembers
vector<Singer> Group::getMembers() { return _members; }

// implement setMembers
void Group::setMembers(vector<Singer> members) { _members = members; }

// implement getName
string Group::getName() { return Artist::getName(); }

// implement getPopularity
int Group::getPopularity() { return Artist::getPopularity(); }

// implement setPopularity
void Group::setPopularity(int popularity) { Artist::setPopularity(popularity); }

// implement getJobName
string Group::getJobName() { return "GroupSinger"; }

// implement constructor
StayC::StayC() : Group("StayC") {}

// implement destructor
StayC::~StayC() {}

// implement instance getter
StayC &StayC::instance()
{
    static StayC *stayc = new StayC();
    return *stayc;
}

// implement getMusic
vector<Music> StayC::getMusic() { return _music; }

// implement setMusic
void StayC::setMusic(vector<Music> music) { _music = music; }

// implement getLightStick
string StayC::getLightStick() { return _lightStick; }

// implement setLightStick
void StayC::setLightStick(string lightStick) { _lightStick = lightStick; }
