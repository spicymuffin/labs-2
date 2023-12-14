#include "Entertainer/Singer/StayC.h"
#include "Entertainer/Singer/Singer.h"

#include <string>
#include <vector>

using namespace std;

// why isgroup definened in StayC.h but oh well...
Group::Group(string name) : Artist(name) {}

vector<Singer> Group::getMembers() { return _members; }

void Group::setMembers(vector<Singer> members) { _members = members; }

string Group::getJobName() { return "GroupSinger"; }

StayC &StayC::instance()
{
    static StayC *stayc = new StayC();
    return *stayc;
}

vector<Music> StayC::getMusic() { return _music; }

void StayC::setMusic(vector<Music> music) { _music = music; }

string StayC::getLightStick() { return _lightStick; }

void StayC::setLightStick(string lightStick) { _lightStick = lightStick; }
